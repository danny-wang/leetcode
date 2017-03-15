/**
179. Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.
For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
Note: The result may be very large, so you need to return a string instead of an integer.
思路：
对所有数进行排序，规则如下：
给定两个非负整数：a, b
将它们转换成字符串形式，然后进行连接。可得两种结果：
  ● a在前，b在后，记为：strAB
  ● b在前，a在后，记为：strBA
如果strAB > strBA，那么排序时a在b的前面。
**/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_string;
        string temp;
        for(auto i : nums){
            stringstream ss;
            ss<<i;
            ss>>temp;
            nums_string.push_back(temp);
            ss.clear();
            ss.str("");
        }
        sort(nums_string.begin(),nums_string.end(),less_second);
        string result;
        for(auto i: nums_string){
            result+=i;
        }
        while(result[0]=='0' && result.size()>1)
            result.erase(0,1);//删除开头的0
        return result;
    }
    static bool less_second(const string & m1, const string & m2) {
        string a=m1+m2;
        string b=m2+m1;
        return a > b; //降序
    }
};
