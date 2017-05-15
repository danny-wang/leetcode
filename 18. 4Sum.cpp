/**
18. 4Sum
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
Find all unique quadruplets in the array which gives the sum of target.
Note: The solution set must not contain duplicate quadruplets.
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
【分析】
  1. 对数组排序
  2. 确定四元数中的前两个（a，b）
  3. 遍历剩余数组确定两外两个（c，d），确定cd时思路跟3Sum确定后两个数据一样，二分查找左右逼近。
  4. 如果与前一个元素大小相同，不用判断，直接继续
**/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size=nums.size();
        if(size<4)
            return {};
        int size_1=size-3;
        int size_2=size-2;
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<size_1;i++){
            if(i>=1 && nums[i]==nums[i-1])
                continue;
            for(int j=i+1;j<size_2;j++){
                if(j>i+1 && nums[j]==nums[j-1])
                    continue;
                int l=j+1;
                int r=size-1;
                long long temp=(long long)nums[i]+nums[j];
                while(l<r){
                    if((long long)nums[l]+nums[r]+temp==target){
                        vector<int> instance={nums[i],nums[j],nums[l],nums[r]};
                        result.push_back(instance);
                        l++;
                        while(l<r && nums[l]==nums[l-1])
                            l++;
                        r--;
                        while(l<r && nums[r]==nums[r+1])
                            r--;
                    }
                    else if ((long long)nums[l]+nums[r]+temp<target){
                        l++;
                        while(l<r && nums[l]==nums[l-1])
                            l++;
                    }
                    else{
                        r--;
                        while(l<r && nums[r]==nums[r+1])
                            r--;
                    }
                }
            }
        }
        return result;
       
    }
};