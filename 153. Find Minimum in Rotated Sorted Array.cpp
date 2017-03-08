/**
153. Find Minimum in Rotated Sorted Array
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
You may assume no duplicate exists in the array.
思路：使用二分法
取数组的中间位置的值：
如果它比数组末尾的值大，说明最小元素就位于[mid + 1, right]之间。
否则，最小元素一定在[left, mid]中。
**/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int left=0,right=nums.size()-1;
        int mid=0;
        while(left<right){
            mid=(left+right)>>1;
            if(nums[mid]>nums[right])
                left=mid+1;
            else if(nums[mid]<nums[right] && nums[mid]>nums[left])
                return nums[left];
            else
                right=mid;
        }
        return nums[left];
    }
};
