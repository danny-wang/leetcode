/**
376. Wiggle Subsequence 
A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence.
For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.
Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2

Follow up:
Can you do it in O(n) time?
 思路1：DP：
先来DP法，对于从index=0到当前位置index=i这段，用dp[i]表示最大的wiggle sequence长度，这个长度肯定是由前面某个位置+1得到的，
而前面某个位置对应的差值数组中的元素可能为正，也可能为负，动归方程为: dp[j]=max(dp[i],i j 构成正负变化) 0<=i<j   
因此需要一个标志位sig 标志i位的时候是正还是负。时间复杂度是O(n^2)
**/class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int size=nums.size();
        vector<int> length(size,1);
        vector<int> sig(nums.size(),2); //0:最后一次是positive, 1:最后一次是negtive
        int max_length=1;
        for(int i=1;i<size;i++){
            int temp_max=1;
            for(int j=i-1;j>=0;j--){
                if(sig[j]==2){
                    if(nums[i]-nums[j]>0 && temp_max<2){
                        sig[i]=0;
                        length[i]=2;
                        temp_max=2;
                    }
                    else if(nums[i]-nums[j]<0 && temp_max<2){
                        sig[i]=1;
                        length[i]=2;
                        temp_max=2;
                    }
                    else
                        continue;
                }
                else{
                    if(nums[i]-nums[j]>0 && sig[j]==1){
                        if(length[j]+1>temp_max){
                            temp_max=length[j]+1;
                            sig[i]=0;
                            length[i]=temp_max;
                        }
                    }
                    else if(nums[i]-nums[j]<0 && sig[j]==0){
                        if(length[j]+1>temp_max){
                            temp_max=length[j]+1;
                            sig[i]=1;
                            length[i]=temp_max;
                        }
                    }
                    else
                        continue;
                }
            }
            if(temp_max>max_length)
                max_length=temp_max;
        }
        return max_length;
    }
};
/**思路2：

而为了能够在O(n)时间内解决可以考虑使用贪心法. 举个栗子: [1,17,5,10,13,15,10,5,16,8], 可以看到前两个[1, 17]确定了一个递增的序列, 而[17, 5]构成了一个递减序列, 所以到目前位置都正常. 到了[10, 13, 15]这里就有问题了, 他们和之前的5构成了一个递增序列, 而出于贪心的考虑, 必然是选择15是最优解, 因为这样给后面序列最大的选择空间. 对于接下来的[10, 5]都与之前的15构成递减区间, 同样道理我们选择5来构造这个序列. 所以一个基于贪心的算法大概就是这样了. 其时间复杂度为(n), 空间复杂度为O(1).
代码如下:
贪心:
**/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int len = nums.size(), ans = len, flag = 0;
        for(int i = 1; i < len; i++)
        {
            if(nums[i]-nums[i-1] == 0) ans--;
            else if(nums[i]-nums[i-1]>0) flag==1?ans--:flag=1;
            else if(nums[i]-nums[i-1]<0) flag==-1?ans--:flag=-1;
        }
        return ans;
    }
};
