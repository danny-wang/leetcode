/**
274. H-Index
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.
According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, 
and the other N − h papers have no more than h citations each."
For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. 
Since the researcher has 3 papers with at least 3citations each and the remaining two with no more than 3 citations each, his h-index is 3.
Note: If there are several possible values for h, the maximum one is taken as the h-index.

分析
题目描述的要求如下：
给定一个整数序列 citations=[3,0,6,1,5]，代表研究人员共有5篇论文，每个元素代表该论文的引用数量。
从序列元素可以看出，该研究人员有至少3篇论文引用数量为>=3的，其余2篇论文引用数量不足3个引用，所以返回他的 h−index=3； 
也就是说，我们找返回一个整数h，使得数组中至少h个元素值大小>=h，其n−h个元素值<h。
解决方法： 
首先对序列排序，然后从大到小遍历数组，h值为从1到n，若元素满足num[i]>h，继续遍历，否则跳出循环，返回h即可。
**/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int result=0;
        int size=citations.size();
        int count=1;
        sort(citations.begin(),citations.end());
        for(int i=size-1;i>=0;i--){
            if(citations[i]>=count){
                result=count;
            }
            count++;
        }
        return result;
    }
};