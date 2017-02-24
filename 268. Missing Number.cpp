/**
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.
For example,
Given nums = [0, 1, 3] return 2.
Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
思路：我的想法是先排序，然后从头到尾看哪一位不对，不对则说明这个位置缺失了。如果从头到尾都没有缺失。那缺失的一定是nums.size().时间复杂度是O（nlogn）.
**/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i==nums[i])
                continue;
            else{
                return i;
            }
        }
        return nums.size();
    }
};
//网上看了更好的思路：等差数列求和，易得缺失值。
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expect = (n+1) * n / 2;
        for(int i = 0; i < n; i ++)
            expect -= nums[i];
        return expect;
    }
};