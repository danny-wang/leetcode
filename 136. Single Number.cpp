/**
Given an array of integers, every element appears twice except for one. Find that single one.
Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
思路：异或，两个相同的数异或等于0,因为只有一个数出现一次，所以所有数异或出来的结果就是那个只出现一次的数字。
**/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result=0;
        for(auto i : nums)
            result= result^i;
        return result; 
    }
};