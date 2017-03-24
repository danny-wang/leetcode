/**
最小的K个数
题目描述
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
思路：
o(nlogK)，适合处理海量数据
用一个大小为K的红黑数去存所有点，遇到小的值就替换最大的
**/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.empty() || k<1 || k>input.size())
            return {};
        multiset<int,greater<int>> result;
        int count=0;
        for(auto i : input){
            if(count<k){
                result.insert(i);
                count++;
            }
            else{
                if(i<*(result.begin())){
                    result.erase(result.begin());
                    result.insert(i);
                }
            }
        }
        vector<int> fin_result;
        for(auto i : result)
            fin_result.push_back(i);
        return fin_result;
    }
};