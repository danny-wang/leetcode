/**
198. House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
思路：这是一个动态规划的问题
f(i,T)表示偷了第i家的最大收获
f(i,F)表示不偷第i家的最大收获
所以有递推公式 F（i, T)= F(i-1,F)+A(i)
F(i, F)=max(F(i-1,T),F(i-1,F))
最终要要求的是max(F(n,F), F(n, T))

For every house k, there are two options: either to rob it (include this house: i) or not rob it (exclude this house: e).
  1. Include this house:
i = num[k] + e (money of this house + money robbed excluding the previous house)
  2. Exclude this house:
e = max(i, e) (max of money robbed including the previous house or money robbed excluding the previous house)
(note that i and e of the previous step, that's why we use tmp here to store the previous i when calculating e, to make O(1) space)

代码：
**/
class Solution {
public:
    int rob(vector<int>& nums) {
        int inclusive=0;
        int exclusive=0;
        int temp;
        for(int i=0;i<nums.size();i++){
            temp=inclusive;//存储i-1个房子偷了的最大收益
            inclusive=exclusive+nums[i];
            exclusive=max(temp,exclusive);
        }
        return max(inclusive,exclusive);
    } 
};