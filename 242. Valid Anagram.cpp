/**
242. Valid Anagram
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
Note:
You may assume the string contains only lowercase alphabets.
Follow up:
What if the inputs contain unicode characters? How would you adapt your solution to such case?
思路1：
Hash Table
This idea uses a hash table to record the times of appearances of each letter in the two strings s and t. 
For each letter in s, it increases the counter by 1 while for each letter in t, it decreases the counter by 1. 
Finally, all the counters will be 0 if they two are anagrams of each other.
**/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> map;
        for(int i=0;i<s.size();i++){
            if(map.find(s[i])!=map.end()){
                map[s[i]]++;
            }
            else
                map[s[i]]=1;
        }
        for(int i=0;i<t.size();i++){
            if(map.find(t[i])!=map.end()){
                map[t[i]]--;
                if(map[t[i]]==0)
                    map.erase(t[i]);
            }
            else
                return false;
        }
        if (map.empty())
            return true;
        else
            return false;
    }
};
/**
思路2：
Sorting
For two anagrams, once they are sorted in a fixed order, they will become the same. 
This code is much shorter (this idea can be done in just 1 line using Python as here).
 However, it takes much longer time --- 76 ms in C++.
 **/
class Solution {
public:
    bool isAnagram(string s, string t) { 
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t; 
    }
};