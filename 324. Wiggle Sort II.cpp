/**
324. Wiggle Sort II.cpp
Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6].
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
Note:
You may assume all input has valid answer.
Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?

这道题给了我们一个无序数组，让我们排序成摆动数组，满足nums[0] < nums[1] > nums[2] < nums[3]...，并给了我们例子。
我们可以先给数组排序，然后在做调整。
调整的方法是找到数组的中间的数，相当于把有序数组从中间分成两部分，然后从前半段的末尾取一个，在从后半的末尾去一个，
这样保证了第一个数小于第二个数，然后从前半段取倒数第二个，从后半段取倒数第二个，这保证了第二个数大于第三个数，且第三个数小于第四个数，
以此类推直至都取完，参见代码如下：
**/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> temp(nums);
        int mid = ((nums.size()-1)>>1);
        int l=mid;int r=nums.size()-1;
        int index=0;
        while(l>0){
            nums[index++]=temp[l--];
            nums[index++]=temp[r--];
        }
        nums[index++]=temp[l];
        if(r!=mid)    //vector元素个数为奇数的时候
            nums[index]=temp[r];
        return ;
    }
};