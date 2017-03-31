/**
第一个只出现一次的字符

题目描述
在一个字符串(1<=字符串长度<=10000，全部由字母组成)中找到第一个只出现一次的字符,并返回它的位置。如果字符串为空,返回-1
思路：用hash的方式，char类型长度为8，总共有256种可能性.

解决这个问题总共扫描两次，第一次记录每个char的出现次数，第二次看它的出现次数是不是1。如果是1就返回
**/
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        if(str.empty())
            return -1;
        int hash_table[256];
        for(int i=0;i<256;i++)
            hash_table[i]=0;
        for(auto i : str){
            hash_table[i]++;
        }
        for(int i=0;i<str.size();i++){
            if(hash_table[str[i]]==1)
                return i;
        }
        return -1;
    }
};