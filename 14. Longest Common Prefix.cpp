/**
14. Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
解法：
思路：设置一个位数记录器num，遍历所有字符串的第num位。如果都相同，则num++。
直到某字符串结束或者所有字符串的第num位不都相同，则返回[0~num-1]位，即最长公共前缀。
时间复杂度：O(nm)（n是字符串数组长度，m是字符串长度）
空间复杂度：O(1)
**/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        int result=0;
        int size=strs.size();
        int min_length=INT_MAX;  //所有string中的最小长度
        for(auto i : strs){
            if(i.size()<min_length)
                min_length=i.size();
        }
        bool not_end=true;
        while(not_end && result<min_length){
            
            char temp=strs[0][result];
            
            for(int i=1;i<size;i++){
                if(strs[i][result]!=temp){
                    not_end=false;
                    break;
                }
            }
            result++;
        }
        if(not_end)
            ;
        else
            result--;
        return strs[0].substr(0,result);
    }
};