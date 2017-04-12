/**
https://www.tianmaying.com/tutorial/LC33
关键字：有序序列，二分查找 - 难度：medium - 题目大意：在一个经过了“旋转”操作的有序序列当中，查找一个特定的值，保证序列中不存在重复的值。
题目描述
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
解法
这道题目在LeetCode当中属于medium难度的题目，其难点主要在于思维难度，这个问题是从标准的二分查找问题引申而出，但是难度却比二分查找难上不上，对于二分查找不熟悉的同学可以先行参考二分查找，来了解一下关于本题的基本知识。
在二分查找的基础上，本题对原本的“有序序列”做了旋转操作，即将整个序列头尾相接视作一个环，然后旋转一定度数，再拆开来形成一个新的序列。
这个序列满足这样的特征，ak+1<ak+2<...<an, a1<a2<...<ak，即从第k+1个数开始分为了两段（1..k, k+1..n），且第一段的所有数字都大于第二段的所有数字。
那么对于这样的问题，我们该如何解决呢？
下面我们来介绍两种不同的做法：
解法1
因为对于一般有序序列的查找是我们掌握范围之内的问题，所以我们不妨将这个经过旋转操作的序列，再进行一定程度的旋转，使其变回一个正常的有序序列，然后就可以在这个正常的有序序列上进行二分查找。
那么关键在于，怎么样使其变回一个正常的有序序列呢？
一个明显的思路就是找到最小的数字，将其旋转回序列的第一个位置，这样就可以得到一个正常的有序序列。
于是问题就变成了怎么样在这样一个经过了旋转的序列中找到最小的值呢？
我们仍然可以尝试使用二分查找的方法：
首先，将问题抽象化，对于一个区间[l, r]，我们希望能够找到这段区间中最小数的坐标，不妨称为q[l, r]，
令 m = (l + r) / 2， 首先我们来看这段区间的构成：
  1. 如果 a[l] < a[r]，说明这段区间是有序的，容易知道 q[l, r] = l
  2. 如果 a[l] > a[r]，说明这段区间是由两段有序区间组成的，此时我们分情况讨论：
2.1 如果 a[m] >= a[l]，说明 m 处于左侧（即较高）的一段有序区间中，因为最小值一定在较低的有序区间中，我们可以知道 q[l, r] = q[m + 1, r]。
2.2 如果 a[m] < a[l]，说明 m 处于右侧（即较低）的一段有序区间中，但因为 a[m] 一定满足 a[m] <= a[r]，即[m + 1, r]中的所有元素都不会是最小值，我们可以知道q[l, r] = q[l, m]。
由于在这样的处理中，每次问题的规模都被缩小了一半，所以最终我们一定会遇到一个问题q[l, r]满足l=r，此时我们就可以知道区间中最小数的坐标为l。
在知道了最小数的坐标之后，我们就可以将其分为两个有序序列：首先在比较要求的元素是否小于等于ａ[n],如果成立的话在ａ[l]到ａ[n]进行二分查找，否则在ａ[0]到ａ[l-1]进行查找。
**/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()==0)
            return -1;
        int l=0, r=nums.size()-1;
        int m=0; //medium value
        //获得最小元素的索引，存到变量l
        while(l<r){
            if(nums[l]<=nums[r])
                break;
            else{
                m=(l+r)/2;
                if(nums[m]>=nums[l])
                    l=m+1;
                else
                    r=m;
            }
        }
        
        int min_index=l;
        r=nums.size()-1;
        if(target==nums[r])
            return r;
        if(target<nums[r]){  //在ａ[l]到ａ[n]进行二分查找
            while(min_index<=r){
                m=(min_index+r)/2;
                if(nums[m]==target)
                    return m;
                if(nums[m]>target)
                    r=m-1;
                if(nums[m]<target)
                    min_index=m+1;
             } 
             
            }
        else{      //ａ[0]到ａ[l-1]进行查找。
            r=l;
            l=0;
            while(l<=r){
                m=(l+r)/2;
                if(nums[m]==target)
                    return m;
                if(nums[m]>target)
                    r=m-1;
                if(nums[m]<target)
                    l=m+1;
            }
            }
        return -1;
        
    }
};
/**
思路2：循环递增数组有这么一个性质：以数组中间元素将循环递增数组划分为两部分，则一部分为一个严格递增数组，而另一部分为一个更小的循环递增数组。
当中间元素大于首元素时，前半部分为严格递增数组，后半部分为循环递增数组；当中间元素小于首元素时，前半部分为循环递增数组；后半部分为严格递增数组。
**/
class Solution {  
public:  
    //二分查找  
    int search(int A[], int n, int target) {  
        int start = 0,end = n-1;  
        int mid;  
        while(start <= end){  
            mid = (start + end) / 2;  
            if(A[mid] == target){  
                return mid;  
            }  
            //中间元素大于最左边元素则左部分为有序数组  
            else if(A[mid] >= A[start]){  
                //目标位于左部分  
                if(target >= A[start] && target <= A[mid]){  
                    end = mid - 1;  
                }  
                //目标位于右部分  
                else{  
                    start = mid + 1;  
                }  
            }  
            //中间元素小于最右边元素则右部分为有序数组  
            else{  
                //目标位于右部分  
                if(target <= A[end] && target >= A[mid]){  
                    start = mid + 1;  
                }  
                //目标位于左部分  
                else{  
                    end = mid - 1;  
                }  
            }  
        }  
        return -1;  
    }  
};  