/**
368. Largest Divisible Subset
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
If there are multiple solutions, return any subset is fine.
Example 1:
nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)

Example 2:
nums: [1,2,4,8]

Result: [1,2,4,8]

思路: 可以用动态规划来解决. 为了使得问题可以转化为子问题, 最好将数组按照降序来排列, 然后当nums[j]%nums[i]==0的时候就可以得到一个状态转移方程dp[i] = max(dp[i], dp[j]+1), 
因为数组按照降序排序, 所以nums[i] < nums[j],并且之前能够被nums[j]整除的数, 也必然能够别nums[i]整除, 这就保证了状态转移方程的正确性. 
他还要求找出最大结果, 所以我们还需要记录一下路径, 每一个数字, 我们记录一个第一个能够使其到达最大长度的父结点, 最后回溯一下即可.
**/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty())
            return {};
        sort(nums.begin(),nums.end(),greater<int>());
        int size=nums.size();
        int max_size=1;
        int max_indice=0;
        vector<int> path(size,0);
        for(int i=0;i<size;i++)
            path[i]=i;
        vector<int> dp(size,1);
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[j]%nums[i]==0){
                    //cout<<"**"<<endl;
                    if(dp[j]+1>=dp[i]){
                        path[i]=j;
                        //cout<<"path[i]:"<<i<<" "<<path[i];
                        dp[i]=dp[j]+1;
                    }
                    if(dp[i]>max_size){
                        max_size=dp[i];
                        max_indice=i;
                        //cout<<max_indice<<endl;
                    }
                }
            }
        }
        //for(auto i : path)
        //    cout<<"i="<<i<<endl;
        vector<int> res;
        while(path[max_indice]!=max_indice){
            //cout<<"path[max_indice]:"<<path[max_indice]<<endl;
            res.push_back(nums[max_indice]);
            max_indice=path[max_indice];
        }
        res.push_back(nums[max_indice]);
        return res;
        
    }
};