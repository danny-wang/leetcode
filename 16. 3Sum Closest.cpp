/**
16. 3Sum Closest
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

思路：首先对给定的数组进行排序，然后从0到数组元素长度len-2开始循环，对于每层循环，定义两个指针一个left指向i+1,right指向数组的尾部，
然后开始判断i,left和start指向的元素之和是否更接近给定的元素，如果接近则更新，
然后判断3个元素的和是大于给定的元素还是小于给定的元素，大于的话left指针加1，小于的话right指针减1；
**/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        int size=nums.size();
        int result=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<size-2;i++){
            if(i>=1 && nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=size-1;
            while(l<r){
                long long sum=(long long)nums[i]+nums[l]+nums[r];
                if(abs((long long)sum-target)<abs((long long)result-target))
                    result=sum;
                if(abs(sum-target)==0)
                    return target;
                else if(sum<target){
                    l++;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                }
                else{
                    r--;
                    while(l<r && nums[r]==nums[r+1])
                        r--;
                } 
            }
        }
        return result;
    }
};
