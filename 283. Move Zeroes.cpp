/**
283. Move Zeroes
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
Note:
  1. You must do this in-place without making a copy of the array.
  2. Minimize the total number of operations.

思路1：
第一次遍历计算0的个数
第二次遍历遇到0就把它之后的所有元素往前移一位，并且把最后一个元素置为0
时间复杂度为O(kn),k为0的个数
**/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size=nums.size();
        int zero_count=0;
        for(int i=0;i<size;i++){
            if(nums[i]==0)
                zero_count++;
        }
        for(int i=0;i<size;i++){
            if(nums[i]==0){
                for(int j=i+1;j<size;j++){
                    nums[j-1]=nums[j];
                }
                nums[size-1]=0;
                zero_count--;
                i--;
                if(zero_count==0)
                    break;
            }
        }
        return;
    }
};
//思路2：
//用j表示应该存放的位置，当nums[i]!=0的时候，就把它放到nums[j]里面，并把j++. 时间复杂度为O(n)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0)
                nums[j++]=nums[i];
        }
        for(;j<nums.size();j++)
            nums[j]=0;
        return;
        
    }
};