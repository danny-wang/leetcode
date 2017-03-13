/**
A peak element is an element that is greater than its neighbors.
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
You may imagine that num[-1] = num[n] = -∞.
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
click to show spoilers.
Note:
Your solution should be in logarithmic complexity.
思路：
最容易想到的是顺序查找，对每一个元素，与它相邻的元素比较。找到第一个满足条件的点，就返回
**/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        for(int i=1; i<nums.size()-1;i++){
            if(nums[i]>nums[i-1]&& nums[i]>nums[i+1])
                return i;
        }
        if(nums[nums.size()-1]>nums[nums.size()-2])
            return nums.size()-1;
        return -1;
    }
};
/**
方法2：
由上面的分析，我们可以得出这样一个规律：
只要数组满足下面的形式：
[ 小，大，... 未知 ...，大，小 ]
那么其中一定能找到peak elememnt。
尝试用二分法处理：
取数组的中间值mid，
  ● 如果mid的值比mid+1的值小
那么从mid开始的数组右半部分将满足：[小，大，...，大，小]的形式，所以其中一定有peak element。
又因为mid肯定不是peak element，所以可以进一步把范围缩小为[mid+1, 数组末尾]。
  ● 如果mid的值比mid+1的值大
那么从数组的开始位置到mid+1位置，也将构成[小，大，...，大，小]的形式。
而mid+1显然也不是peak element。所以可进一步把范围缩小到[数组开始，mid]。
它的时间复杂度是：O(log n)。
代码如下：
**/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left=0;
        int right=nums.size()-1;
        while(left<right){
            int mid=(left+right)>>1;
            if(nums[mid]<nums[mid+1])
                left=mid+1;
            else // nums[mid] > nums[mid + 1]
                right=mid;
        }
        return left;
    }
};