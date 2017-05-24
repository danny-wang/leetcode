/**
383. Ransom Note 
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.
Each letter in the magazine string can only be used once in your ransom note.
Note:
You may assume that both strings contain only lowercase letters.
canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true


思路：用哈希的思想：原理就是列出了magazine的字母表，然后算出了出现个数，然后遍历ransomNote，保证有足够的字母可用，代码非常清晰。
**/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(256,0);
        int size=magazine.size();
        for(int i=0;i<size;i++){
            hash[magazine[i]]++;
        }
        size=ransomNote.size();
        for(int i=0;i<size;i++){
            hash[ransomNote[i]]--;
            if(hash[ransomNote[i]]<0)
                return false;
        }
        return true;
    }
};