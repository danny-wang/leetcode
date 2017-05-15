/**
121. Best Time to Buy and Sell Stock
http://blog.csdn.net/ljiabin/article/details/44900389

Say you have an array for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)

Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
思路：

How to get max_pro? Just get the larger one between current max_pro and prices[i] - min_price.
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price=INT_MAX;  //minimum price from day 0 to day i
        int max_pro=0;//maximum profit we can get from day 0 to day i.
        for(int i=0;i<prices.size();i++){
            min_price=min(min_price, prices[i]);
            max_pro=max(max_pro, prices[i]-min_price);
        }
        return max_pro;
        
    }
};