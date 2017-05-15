/**
300. Longest Increasing Subsequence
Given an unsorted array of integers, find the length of longest increasing subsequence.
For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?

分析：
求数组的最长递增子序列。经典dp问题，在很多大学讲DP的教程里，都会出现这道题以及Longest Common Subsequence。 这里其实也有O(nlogn)的方法，比如Patience Sorting一类的，二刷再研究。下面我们来看DP。初始化dp[i] = 1，即一个元素的递增序列。 假设以i - 1结尾的subarray里的LIS为dp[i - 1]，那么我们要求以i结尾的subarray里的LIS，dp[i]的时候，要把这个新的元素和之前所有的元素进行比较，如果前面有比它小的元素，则可以和它连接起来形成一个新的LIS，长度为dp[j] + 1，同时逐步比较dp[j] + 1与dp[i]，假如发现更长的序列，我们则更新dp[i] = dp[j] + 1，继续增加j进行比较。当i之前的元素全部遍历完毕以后，我们得到了当前以i结尾的subarray里的LIS，就是dp[i]。
Time Complexity - O(n2)， Space Complexity - O(n)。

例如：
比如题中给出的例子[10, 9, 2, 5, 3, 7, 101, 18], 其中最长的上升子序列是 [2, 3, 7, 101]。
对于每一个元素，都有可能跟前面的序列构成一个较长的上升序列，或者跟后面的序列构成一个较长的上升序列
（1）对于10这个元素，它是第一个，所以它构成的最长上升子序列长度为1；
（2）对于9这个元素，前面没有比它小的，所以它构成的最长上升子序列长度为1；
（3）对于2这个元素，遍历前面的10和9，没有比它小的，所以它构成的最长上升子序列长度为1；
（4）对于5这个元素，遍历前面的10，9，2，发现2比它小，所以能和2构成最长上升子序列，2的最长上升子序列的长度为1，所以5的最长上升子序列长度是1+1=2；
（5）对于3这个元素，遍历前面的10，9，2，5，发现2比它小，所以能和2构成最长上升子序列，2的最长上升子序列的长度为1，所以3的最长上升子序列长度是1+1=2；
（6）对于7这个元素，遍历前面10，9，2，5，3，发现2，5，3，比它小，找2，5，3谁的最长上升子序列长度最长，最长值加1，得到了长度2+1=3；
（7）对于101这个元素，遍历前面的10，9，2，5，3，7，发现都比它小，找前面的10，9，2，5，3，7谁的最长上升子序列最长，发现7的子序列长度最大，最大值加1，得到长度4.
（8）对于18这个元素，遍历前面的10，9，2，5，3，7，101，发现10，9，2，5，3，7比它小，找这几个元素谁的最长上升子序列最长，最长值3加1，得到了3+1=4；
**/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int size=nums.size();
        vector<int> longest(size,1);  //存储以i结尾的子串中的LIS
        int result=1;
        for(int i=0;i<size;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(longest[i]<(longest[j]+1)){
                        longest[i]=(longest[j]+1);
                        if(longest[i]>result)
                            result=longest[i];
                    }
                }
            }
        }
        return result;
    }
    
};
/**
O(nlogn)时间复杂度：
假设存在一个序列d[1..9] = 2 1 5 3 6 4 8 9 7，可以看出来它的LIS长度为5。
下面一步一步试着找出它。
我们定义一个序列B[1..9]，B[i]指的是第i长的最长上升子序列的最后一个元素是什么。
然后令 i = 1 to 9 逐个考察这个序列。
此外，我们用一个变量Len来记录现在最长算到多少了

首先，把d[1]有序地放到B里，令B[1] = 2，就是说当只有1一个数字2的时候，长度为1的LIS的最小末尾是2。这时Len=1

然后，把d[2]有序地放到B里，令B[1] = 1，就是说长度为1的LIS的最小末尾是1，d[1]=2已经没用了，很容易理解吧。这是因为此时的最长序列长度没有改变但序列的''潜力''增大了。 这时Len=1

接着，d[3] = 5，d[3]>B[1]，所以令B[1+1]=B[2]=d[3]=5，就是说长度为2的LIS的最小末尾是5，很容易理解吧。这时候B[1..2] = 1, 5，Len＝2

再来，d[4] = 3，它正好加在1,5之间，放在1的位置显然不合适，因为1小于3，长度为1的LIS最小末尾应该是1，这样很容易推知，长度为2的LIS最小末尾是3，于是可以把5淘汰掉，这时候B[1..2] = 1, 3，Len = 2

继续，d[5] = 6，它在3后面，因为B[2] = 3, 而6在3后面，于是很容易可以推知B[3] = 6, 这时B[1..3] = 1, 3, 6，还是很容易理解吧？ Len = 3 了噢。

第6个, d[6] = 4，你看它在3和6之间，于是我们就可以把6替换掉，得到B[3] = 4。B[1..3] = 1, 3, 4， Len继续等于3

第7个, d[7] = 8，它很大，比4大，嗯。于是B[4] = 8。Len变成4了

第8个, d[8] = 9，得到B[5] = 9，嗯。Len继续增大，到5了。

最后一个, d[9] = 7，它在B[3] = 4和B[4] = 8之间，所以我们知道，最新的B[4] =7，B[1..5] = 1, 3, 4, 7, 9，Len = 5。

于是我们知道了LIS的长度为5。

!!!!! 注意。这个1,3,4,7,9不是LIS，它只是存储的对应长度LIS的最小末尾。有了这个末尾，我们就可以一个一个地插入数据。虽然最后一个d[9] = 7更新进去对于这组数据没有什么意义，但是如果后面再出现两个数字 8 和 9，那么就可以把8更新到d[5], 9更新到d[6]，得出LIS的长度为6。

然后应该发现一件事情了：在B中插入数据是有序的，而且是进行替换而不需要挪动——也就是说，我们可以使用二分查找，将每一个数字的插入时间优化到O(logN)~~~~~于是算法的时间复杂度就降低到了O(NlogN)～！

**/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        vector<int> helper(nums.size(),0);
        helper[0]=nums[0];
        int lis=0;
        for(int i=1;i<nums.size();i++){
            int temp=FindFisrtBiggerVal(helper,0, lis, nums[i]);
            swap(helper[temp],nums[i]);
            if(temp>lis)
                lis=temp;
        }
        return lis+1;
    }
    int FindFisrtBiggerVal(vector<int>& helper, int l, int r, int val){
        while(l<=r){
            int mid=(l+r)>>1;
            if(helper[mid]==val)
                return mid;
            else if(helper[mid]<val)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
};