/**
13. Roman to Integer
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
解题思路：
罗马数字是符号和加操作的一个组合。他基于以下七个符号。
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

II is 2, and XIII is 13. 罗马数字没有0，所以 207是CCVII，1066 is MLXVI.
计数规则：
1. 若干相同数字连写表示的数是这些罗马数字的和，如 III=3；
2. 小数字在大数字前面表示的数是用大数字减去小数字，如 IV＝4；
3. 小数字在大数字后面表示的数是用大数字加上小数字，如 VI=6;
其中每两个阶段的之间有一个减法的表示，比如 900=CM， C 写在 M 前面表示 M-C。
组合规则：
(1) 基本数字 Ⅰ、X 、C 中的任何一个，自身连用构成数目，或者放在大数的右边连用构成数目，都不能超过三个；放在大数的左边只能用一个。
(2) 不能把基本数字 V 、L 、D 中的任何一个作为小数放在大数的左边采用相减的方法构成数目；放在大数的右边采用相加的方式构成数目，只能使用一个。
(3) V 和 X 左边的小数字只能用 Ⅰ。
(4)L 和 C 左边的小数字只能用 ×。
(5)D 和 M 左 边的小数字只能用 C 。
还有一点需要格外注意 MCM是1900
MCMXCVI是1996 也就是按照逻辑 遍历到C 的处理，MC先M+C，但是遍历到第二个M的时候，顺序是CM，这个时候要减去这个C以及之前多加的C，也就是减去两个C。
**/
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> map;
        map['I']=1;
        map['V']=5;
        map['X']=10;
        map['L']=50;
        map['C']=100;
        map['D']=500;
        map['M']=1000;
        int result=0;
        if(s.size()>=1)
            result+=map[s[0]];
        else
            return result;
        for(int i=1;i<s.size();i++){
            if(map[s[i]]<=map[s[i-1]])
                result+=map[s[i]];
            else
                result=result+map[s[i]]-2*map[s[i-1]];
        }
        return result;
    }
};


