/**
238. Product of Array Except Self
Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).
For example, given [1,2,3,4], return [24,12,8,6].
Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
思路：
创建两个辅助数组，一个保存所有左边元素乘积的结果。一个保存所有右边元素乘积的结果。借助这两个数组，一次遍历就可以得到结果。
**/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> l,r,result;
        int size=nums.size();
        int temp=1;
        l.push_back(1);
        for(int i=0;i<size-1;i++){
            temp*=nums[i];
            l.push_back(temp);    
        }
        temp=1;
        r.push_back(1);
        for(int i=size-1;i>=1;i--){
            temp*=nums[i];
            r.push_back(temp);
        }
        for(int i=0;i<size;i++)
            result.push_back(l[i]*r[size-i-1]);
        return result;
    }
};
//这样算法的时间复杂度为O（n），但算法空间复杂度也为O（n），不满足空间O（1）的需求.
//题目中提到 返回的结果不计空间，所以直接在result中保存left值。 right 值用变量代替，