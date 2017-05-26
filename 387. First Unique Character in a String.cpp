/**
387. First Unique Character in a String 
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
Examples:
s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string contain only lowercase letters.
思路1：Brute force solution, traverse string s 2 times. First time, store counts of every character into the hash table, second time, find the first character that appears only once.
**/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> map;
        for(auto i : s){
            if(map.find(i)==map.end())
                map[i]=1;
            else
                map[i]++;
        }
        int size=s.size();
        for(int i=0;i<size;i++){
            if(map[s[i]]==1)
                return i;
        }
        return -1;
    }
};
//思路2：if the string is extremely long, we wouldn't want to traverse it twice, so instead only storing just counts of a char, we also store the index, and then traverse the hash table.
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> m;
        int idx = s.size();
        for(int i = 0; i < s.size(); i++) {
            m[s[i]].first++;
            m[s[i]].second = i;
        }
        for(auto &p : m) {
            if(p.second.first == 1) idx = min(idx, p.second.second);
        }
        return idx == s.size() ? -1 : idx;
    }
};