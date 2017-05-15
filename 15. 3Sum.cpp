/**
15. 3Sum
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.
Note: The solution set must not contain duplicate triplets.
For example, given array S = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]


先升序排序，然后用第一重for循环确定第一个数字。
然后在第二重循环里，第二、第三个数字分别从两端往中间扫。
如果三个数的sum等于0，得到一组解。
如果三个数的sum小于0，说明需要增大，所以第二个数往右移。
如果三个数的sum大于0，说明需要减小，所以第三个数往左移。
时间复杂度：O(n2)
注意：
1、排序之后天然满足non-descending order的要求
2、为了避免重复，在没有空间要求情况下可以用map，但是也可以跳过重复元素来做。
**/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int size=nums.size();
        int size_1=size-2;
        for(int i=0;i<size_1;i++){
            if(i>=1 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=size-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    vector<int> a={nums[i],nums[l],nums[r]};
                    result.push_back(a);
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                }
                else if(nums[i]+nums[l]+nums[r]<0){
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
        return result;
    
    }
};