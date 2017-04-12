/**
81. Search in Rotated Sorted Array II 

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Write a function to determine if a given target is in the array.
The array may contain duplicates.
【分析】
相比上一道题，这道题允许重复元素出现，则上一道题中的A[start] <= A[mid] 条件就不能确定[start mid]区间为递增有序序列了。
比如：｛1，3，1，1，1，1｝
如果A[start] <= A[mid] 条件就不能确定[start mid]区间为递增有序序列，我们就把该条件分成两个字条件：
A[start] < A[mid] 则 [start mid]区间为递增有序序列
A[start] = A[mid] 则[start mid]区间不能确定，那就start++，往下一步看看即可。
**/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size()==0)
        	return 0;
      	int left=0;
        int right=nums.size()-1;
        while(left<=right){
            int mid=(left+right)>>1;
            if(target==nums[mid])
                return true;
            if(nums[mid]>nums[left]){//mid左边为有序序列
                if(target>=nums[left] && target<=nums[mid])//在mid的左边
                    right=mid-1;
                else
                    left=mid+1;
            }
            else if(nums[mid]<nums[left]){//mid右边为有序序列
                if(target>=nums[mid] && target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
            else //nums[mid]==nums[left] 无法区分哪边有序
                left++;
        }
        return false;
        
    }
    
    
};