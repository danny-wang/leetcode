/**
213. House Robber II
Note: This is an extension of House Robber.
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. 
This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. 
Meanwhile, the security system for these houses remain the same as for those in the previous street.
Given a list of non-negative integers representing the amount of money of each house, 
determine the maximum amount of money you can rob tonight without alerting the police.
思路：
这个问题其实就是198题的变种，因为第一家与最后一家连起来了，不能同时偷，所以解决这个问题也就是求：
（1）偷0-------n-1家的最大收益
（2）偷1--------n家的最大收益
两者里面求最大值。
**/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int a=rob_line_streat(nums,0,nums.size()-1);
        int b=rob_line_streat(nums,1,nums.size());
        return max(a,b);
    }
    int rob_line_streat(vector<int>& nums, int left, int right){
        int i=0;
        int e=0;
        int temp;
        for(int j=left;j<right;j++){
            temp=i;
            i=e+nums[j];
            e=max(temp,e);
        }
        return max(i,e);
    }
};