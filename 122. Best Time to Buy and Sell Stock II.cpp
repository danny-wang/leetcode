/**
122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

解题思路
  ● 在Best Time to Buy and Sell Stock系列中，和本题最像的是Best Time to Buy and Sell Stock IV
  ● Best Time to Buy and Sell Stock IV中是求某个给定k次交易的最大收益，和Maximum Subarray III完全一样
  ● 本题由于是可以操作任意次数，只为获得最大收益，而且对于一个上升子序列，比如：[5, 1, 2, 3, 4]中的1, 2, 3, 4序列来说，对于两种操作方案：
1 在1买入，4卖出
2 在1买入，2卖出同时买入，3卖出同时买入，4卖出
这两种操作下，收益是一样的。
  ● 所以可以从头到尾扫描prices，如果price[i] – price[i-1]大于零则计入最后的收益中。即贪心法
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                result+=prices[i]-prices[i-1];
        }
        return result;
    }
};