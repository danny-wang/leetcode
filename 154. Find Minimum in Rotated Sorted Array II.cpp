/**
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
Find the minimum element.
The array may contain duplicates.
思路：
剑指offer P66
因为有重复元素，所以有可能两个指针指向的数字以及他们中间的数字三者相同，这时，我们只能顺序查找
代码：
**/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int index1=0;   //左边子串的最大值
        int index2=nums.size()-1;   //右边子串的最小值
        int index_mid=index1;   //如果是排好序的，可以直接返回
        while(nums[index1]>=nums[index2]){
            if((index2-index1)==1){
                index_mid=index2;
                break;
            }
            index_mid=((index2+index1)>>1);
            if(nums[index_mid]==nums[index1]&&nums[index_mid]==nums[index2]){
                return MinInOrder(nums, index1, index2);
            }
            if(nums[index_mid]>=nums[index1])
                index1=index_mid;
            else if(nums[index_mid]<=nums[index2])
                index2=index_mid;
        }
        return nums[index_mid];
    }
    int MinInOrder(vector<int>& nums, int left, int right){
        int min=nums[left];
        for(int i=left+1; i<=right; i++){
            if(min>nums[i])
                min=nums[i];
        }
        return min;
    }
};
