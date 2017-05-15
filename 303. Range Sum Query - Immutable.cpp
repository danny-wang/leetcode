/**
303. Range Sum Query - Immutable
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3

Note:
  1. You may assume that the array does not change.
  2. There are many calls to sumRange function.

分析
给定一个整数序列，求指定子序列和。
提示：数组不会发生变化；大量sumRange函数调用。
题目本身非常简单，只需要遍历 i 到 j ，累计得到和即可。但是，这样是TLE的，所给提示也就没有意义了。
所以，题目考察的是效能，换一个方向思考，我们可以存储子序列和，每个下标处的值为[0,i]的所有元素和;
那么[i,j]子序列和 =sum[j]−sum[i−1]；
注意，i==0时，直接返回sum[j]即可。
**/
class NumArray {
public:
    NumArray(vector<int> nums) {
        int temp=0;
        for(int i=0;i<nums.size();i++){
            temp+=nums[i];
            mid.push_back(temp);
        }
    }
    
    int sumRange(int i, int j) {
        if(i==0)
            return mid[j];
        else
            return mid[j]-mid[i-1];
    }
private:
    vector<int> mid;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */