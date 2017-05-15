/**
334. Increasing Triplet Subsequence

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.
Examples:
Given [1, 2, 3, 4, 5],
return true.
Given [5, 4, 3, 2, 1],
return false.

思路：本题可以用最长升序子序列的方法来做，但是有点小题大做了。还可以维护一个当前的长度为2的升序序列(小的值叫small, 大的叫big)，
如果碰到比第二个值大的说明可以找到升序的三个值。并且在过程中不断更新small和big的值，使得他们最小。
**/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size=nums.size();
        int small=INT_MAX;
        int big=INT_MAX;
        for(int i=0;i<size;i++){
            if(nums[i]<=small)
                small=nums[i];
            else if(nums[i]<=big)
                big=nums[i];
            else
                return true;
        }
        return false;
    }
};