/**
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example:
Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
  1. The order of the result is not important. So in the above example, [5, 3] is also correct.
  2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

思路：
假设nums中2个不同的数为a和b，通过计算nums的异或运算就能求出a和b的异或值，定为c。那么c的二进制表示中，从右开始数的第一个1即为a和b的二进制形式在该位上肯定是不同的值。
假如a = 0101, b = 0011, 那么a^b=0110, 那么a和b是在从右往左数的第二位值不同。设置bit=010，将nums里的每个数&bit, 便可将nums分成2组了，每组的异或值就是a或者b了。
**/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum_of_two=0;
        for(auto i : nums)
            sum_of_two ^= i;  //get the sum of two elements that appear only once
        sum_of_two &= -sum_of_two; //get last index equals 1
        //split the vector to two parts, each contains one unique element;
        int element_a=0, element_b=0;
        for(auto i : nums){
            if(i & sum_of_two)
                element_a ^=i;
            else
                element_b ^=i;
        }
        vector<int> result={element_a, element_b};
        return result;
    }
};
