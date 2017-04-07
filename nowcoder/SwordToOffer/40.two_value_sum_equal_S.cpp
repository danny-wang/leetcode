/**
和为S的两个数字

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，是的他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
输出描述:
对应每个测试案例，输出两个数，小的先输出。

思路：两个指针，一个指向头，一个指向尾，如果和等于S，就加入，如果小于S，增大头指针，如果大于S，减小尾指针
**/
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        if(array.empty())
            return {};
        vector<vector<int>> all_result;
        bool has_result=false;
        int left=0;
        int right=array.size()-1;
        while(left<right){
            if(array[left]+array[right]==sum){
                has_result=true;
                vector<int> temp={array[left],array[right]};
                all_result.push_back(temp);
                right--;
            }
            else if(array[left]+array[right]>sum){
                right--;
            }
            else{//array[left]+array[right]<sum
                left++;
            }
        }
        if(has_result==false)
            return {};
        else{
            int a=all_result[0][0];
            int b=all_result[0][1];
            int temp= all_result[0][0]*all_result[0][1];
            for(auto i : all_result){
                if(i[0]*i[1]<temp){
                    temp=i[0]*i[1];
                    a=i[0];
                    b=i[1];
                }
            }
            vector<int> result={a,b};
            return result;
        }
    }
};