/**
373. Find K Pairs with Smallest Sums 
You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
Define a pair (u,v) which consists of one element from the first array and one element from the second array.
Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]

思路: 一种naive的做法是产生所有组合然后排序, 取最小的k个即可, 这种时间复杂度为O(mn log(mn)). 还有一种不需要产生所有的组合, 这种思想有点像寻找第k个丑数, 记录一下nums1中每个数对应nums2中组合的位置. 然后每次找到能够产生最小的组合即可.时间复杂度O(kn)
思路2： 也可以用优先队列实现
**/
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int size1=nums1.size();
        int size2=nums2.size();
        if(k<=0 || nums1.empty() || nums2.empty())
            return {};
        if(k>size1*size2)
            k=size1*size2;
        vector<int> index(size1,0);//nums1中每一个元素可能存在最小和的对应nums2的下标
        vector<pair<int,int>> res;
        while(k>0){
            long long sum=(long long)INT_MAX*3;
            int a=0;
            for(int i=0;i<size1;i++){
                if(index[i]<size2){
                    if((long long)nums1[i]+nums2[index[i]]<sum){
                        sum=(long long)nums1[i]+nums2[index[i]];
                        a=i;
                    }
                }
            }
            res.push_back(make_pair(nums1[a],nums2[index[a]]));
            index[a]++;
            k--;
        }
        return res;
    }
};
