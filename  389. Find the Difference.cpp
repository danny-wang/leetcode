/**
 389. Find the Difference 
 Given two strings s and t which consist of only lowercase letters.
String t is generated by random shuffling string s and then add one more letter at a random position.
Find the letter that was added in t.
Example:
Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.
思路1：用数组去模拟hash
因为字符串只有小写字母，也就是只有26中可能，那么建立一个int[26]的数组即可，索引就是字符char-'a'，而数组值就是字符出现在字符串s中的次数
首先遍历字符串s，来建立这个map，然后再遍历字符串t。对t中出现的每个字符，都从map中减一，当value值小于0时，则说明该字符就是多出的字符
**/
class Solution {
public:
    char findTheDifference(string s, string t) {
        int hash[26];
        memset(hash,0,26*sizeof(int));
        for(auto i : s)
            hash[i-'a']++;
        for(auto i : t){
            if(hash[i-'a']==0)
                return i;
            else
                hash[i-'a']--;
        }
        return 'a';
    }
};
//解法2：由于字符串t只比字符串s多了一个字符，那么直接用t中所有字符值的和减去字符串s中字符值的和即可。
public char findTheDifference(String s, String t) {
    int ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret -= (int)s.charAt(i);
    }
    for (int i = 0; i < t.length(); i++) {
        ret += (int)t.charAt(i);
    }
    return (char)ret;
}
//解法3：另外一种思路，既然字符串t只比字符串s多了一个字符，也就是说大部分字符都是相同的。那么，我们可以使用异或的方式，来找出这个不同的值。
public char findTheDifference(String s, String t) {
    int ret = 0;
    for (int i = 0; i < s.length(); i++) {
        ret ^= s.charAt(i);
    }
    for (int i = 0; i < t.length(); i++) {
        ret ^= t.charAt(i);
    }
    return (char)ret;
}
