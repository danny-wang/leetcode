/**
377. Combination Sum IV 
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
Example:
nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

动态规划状态方程：
dp[target]=sum(dp[target-nums[i]]) (for i=0..num.size()-1)
dp[target] 代表一共有多少种可能。
那么从target-nums[i] 变为 target，只有一种途径，也就是加上nums[i];那么这种途径带来的次数是dp[target-nums[i]];
我们遍历所有的nums[i],然后求和即可以得到dp[target]的结果。
如果允许有负数的话就必须要限制每个数能用的次数了, 不然的话就会得到无限大的排列方式, 比如1, -1, target = 1;
**/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int size=nums.size();
        vector<int> dp(target+1,0);
        dp[0]=1; //如果有自身，那就是一种可能
        for(int i=1;i<=target;i++){
            for(auto j : nums){
                if(i-j>=0)
                    dp[i]+=dp[i-j];
            }
        }
        return dp[target];
        
    }
    
};