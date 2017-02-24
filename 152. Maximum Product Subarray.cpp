/**
Find the contiguous subarray within an array (containing at least one number) which has the largest product.
For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
解题思路：乘法与加法最大差别在于，当前元素的符号具有全局性的作用。
如果当前元素为负，那么连乘到上个元素的最大乘积，再乘以当前元素，就变成负数，甚至可能成为最小乘积。
同样，连乘到上个元素的最小乘积如为负，再乘以当前元素，就变成正数，甚至可能成为最大乘积。
 
因此使用动态规划的方法：
记max_last/min_last为连乘到上个元素的最大/小乘积
记max_cur/min_cur为连乘到当前元素的最大/小乘积
记max_all为全局最大乘积
**/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int min_last=nums[0];
        int min_cur=0;
        int max_last=nums[0];
        int max_cur=0;
        int max_all=nums[0];
        for(int i=1;i<nums.size();i++){
            min_cur=min(nums[i], min(min_last*nums[i], max_last*nums[i]));
            max_cur=max(nums[i], max(min_last*nums[i], max_last*nums[i]));
            max_all= (max_all> max_cur? max_all : max_cur);
            min_last=min_cur;
            max_last=max_cur;
        }
            return max_all;
    }
};