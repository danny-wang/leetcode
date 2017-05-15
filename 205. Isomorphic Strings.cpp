/**
205. Isomorphic Strings
Given two strings s and t, determine if they are isomorphic.
Two strings are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
For example,
Given "egg", "add", return true.
Given "foo", "bar", return false.
Given "paper", "title", return true.
Note:
You may assume both s and t have the same length.
思路：
此题的关键是要保证s与t中每一个字符之间都是一一对应的关系（即不能出现一对多或多对一的情况）。
建一个map保存映射关系, 同时用一个set保持 被映射的char, 保证同一个char 不会被映射两次.
**/
class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.empty() && t.empty())
			return true;
		if (s.size() != t.size())
			return false;
		int size = s.size();
		unordered_map<char, char> m;
		unordered_set<char> set;
		for (int i = 0; i<size; i++){
			if (m.find(s[i]) == m.end()){  //以前不存在这种映射
				if (set.find(t[i]) != set.end())
					return false;
				else{
					m[s[i]] = t[i];
					set.insert(t[i]);
				}
			}
			else{   //以前已经有了映射关系
				if (m[s[i]] == t[i])
					continue;
				else
					return false;
			}
		}
		return true;
	}
};