 /**
345. Reverse Vowels of a String 
Write a function that takes a string as input and reverse only the vowels of a string.
Example 1:
Given s = "hello", return "holle".
Example 2:
Given s = "leetcode", return "leotcede".
Note:
The vowels does not include the letter "y".
思路：
首先定义一个方法去判断一个char字符是否是元音字母。然后通过首尾两个”指针”，当前后两个字符都是元音字符的时候才进行交换，否则将不是元音字符的指针向前或者向后移动。
跳出条件就是start < end。
**/
class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty())
            return s;
        string temp(s);
        auto ite_l=temp.begin();
        auto ite_r=temp.end()-1;
        while(ite_l<ite_r){
            while(ite_l<ite_r){
                if((*(ite_l)=='a'||*(ite_l)=='e'||*(ite_l)=='i'||*(ite_l)=='o'||*(ite_l)=='u'||*(ite_l)=='A'||*(ite_l)=='E'||*(ite_l)=='I'||*(ite_l)=='O'||*(ite_l)=='U'))
                    break;
                else
                    ite_l++;
            }
            while(ite_l<ite_r){
                if((*(ite_r)=='a'||*(ite_r)=='e'||*(ite_r)=='i'||*(ite_r)=='o'||*(ite_r)=='u'||*(ite_r)=='A'||*(ite_r)=='E'||*(ite_r)=='I'||*(ite_r)=='O'||*(ite_r)=='U'))
                    break;
                else
                    ite_r--;
            }
            if(ite_l<ite_r){
                swap(*(ite_l),*(ite_r));
                ite_l++;
                ite_r--;
            }
        }
        return temp;
    }
};