/**
189. Rotate Array
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
Note:
Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
思路一：首先计算需要旋转的位置，然后先存后面一部分，在存前面一部分
**/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k>nums.size()){  //计算需要旋转的位置
            k=k%nums.size();
        }
        vector<int> temp;
        for(int i= nums.size()-k; i<nums.size();i++) //后面一部分
            temp.push_back(nums[i]);
        for(int i=0; i<nums.size()-k; i++)  //前面一部分
            temp.push_back(nums[i]);
        nums=temp;
    }
};
/**
思路2：do it in-place with O(1) extra space
一步一步地挪动,具体解答如下：k=2
初始数组：1, 2, 3, 4, 5, 6
右移一步:   5, 1, 2, 3, 4, 6
右移二步:   5, 6, 1, 2, 3, 4
**/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        while(k>nums.size()){
            k=k%nums.size();
        }
        int left=0;//需要向后移动的起始位置
        int temp=0;
        for(int i= nums.size()-k; i<nums.size();i++){
            temp=nums[i];
            for(int j = i; j>left;j--){
                swap(nums[j],nums[j-1]);
            }
            nums[left]=temp;
            left++;
        }
        return;
    }
};
/**
思路3：
很神奇，一共有3步。假设输入数组的下标是0~ n-1，需要rotate的步数是k.
step 1 reverse原来的数组
step 2 reverse 0~ k-1
step 3 reverse k ~ n-1
**/