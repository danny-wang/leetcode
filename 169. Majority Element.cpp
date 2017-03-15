/**
169. Majority Element
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
思路一Time Limit Exceeded：  
利用快速排序的思想，每次选一个数，将它放在对的位置上，如果刚好在n/2的位置上，就是答案，否则分情况讨论，平均时间复杂度是O（n），
但是如果是排好序的，则时间复杂度是O（n^2）.
**/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return FindMajorityElement(nums, 0, nums.size()-1);
    }
    int FindMajorityElement(vector<int>& nums, int a, int b){
        int left=a;
        int right=b;
        int temp=nums[left];
        while(left<right){
            while(nums[right]>=temp && left<right ){
                right--;
            }
            while(nums[left]<=temp && left<right){
                left++;
            }
            if(left<right)
                swap(nums[left],nums[right]);
        }
        nums[a]=nums[left];
        nums[left]=temp;
        if(left==(nums.size()>>1))
            return nums[left];
        else if(left<(nums.size()>>1))
            return FindMajorityElement(nums, left+1,b);
        else
            return FindMajorityElement(nums, a,left-1 );  
    }
};
/**
思路2：
数组中有一个数字出现的次数超过数组长度的一半，也就是说它出现的次数比其他所有数字出现的次数的和还要多。
在遍历的时候保存两个值，一个是当前数字，一个是次数。当遍历下一个数字的时候，如果与之前保存的数字一致，则次数加一，如果不一致，则次数减一。
如果次数为0，则保存下一个数字，并把次数设为一。
**/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur_val=nums[0];
        int count=1;
        for(int i=1;i<nums.size(); i++){
            if(nums[i]==cur_val)
                count++;
            else if(nums[i]!=cur_val && count==0){
                cur_val=nums[i];
                count=1;
            }
            else
                count--;
        }
        return cur_val;
    }
};