/**
 * Given an array of strings, group anagrams together.
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note: All inputs will be in lower-case.

该题目要求是将给定的一组字符串数组，按照同构词（相同字母组成的单词）分类，每组单词按照字典排序。

思路：利用STL的map容器将每一个字符串排过序之后作为key，value就保存所有的具有相同字母的字符串．
然后这样遍历一遍就把所有的字符串都保存在了map中，然后对每个key所代表的集合排过序之后输出到结果数组中即可．
**/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        map<string,vector<string>> group;
        for(auto a : strs){
            string b=a;
            sort(b.begin(),b.end());
            group[b].push_back(a);
        }
        for(auto a : group )
            result.push_back(a.second);
        return result;
    }
};
