/**
290. Word Pattern
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
Examples:
  1. pattern = "abba", str = "dog cat cat dog" should return true.
  2. pattern = "abba", str = "dog cat cat fish" should return false.
  3. pattern = "aaaa", str = "dog cat cat dog" should return false.
  4. pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
[思路]
char 和 string 一一对应. 建一个map. 同时set里面保存string, 避免重复, 出现多对1的情况. 
**/
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char,string> map;
        unordered_set<string> set;
        stringstream ss;
        ss.str(str);
        for(int i=0;i<pattern.size();i++){
            if(map.find(pattern[i])==map.end()){ //没有找到匹配
                string temp;
                ss>>temp;
                //cout<<"if: "<<temp<<endl;
                if(temp.empty() || set.find(temp)!=set.end())
                    return false;
                map[pattern[i]]=temp;
                set.insert(temp);
            }
            else{
                string temp;
                ss>>temp;
                //cout<<"else: "<<temp<<endl;
                if(temp.empty() || temp!=map[pattern[i]])
                    return false;
                else
                    continue;
            }
        }
        string temp;
        ss>>temp;
        //cout<<temp.empty()<<temp<<endl;
        if(temp.empty())
            return true;
        else
            return false;
    }
};