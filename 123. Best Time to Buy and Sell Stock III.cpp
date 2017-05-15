/**
123. Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most two transactions.
Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

动态规划
使用两个数组，pre_pro和post_pro。
pre_pro[i]表示从0到i的最优买卖值（低买高卖，为正）。需要一次从左往右遍历。
post_pro[i]表示从m-1到i的最差买卖值（高买低卖，为负）。需要一次从右往左遍历。
再对应元素相减：pre_pro[i]-post_pro[i]的最大值即解。
**/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int size=prices.size();
        int *pre_pro=new int[size];
        int *post_pro=new int[size];
        int *result = new int[size];
        int final_result=0;
        GetProfit(prices, pre_pro, post_pro);
        for(int i=0;i<size;i++){
            result[i]=pre_pro[i]+post_pro[i];
            if(result[i]>final_result)
                final_result=result[i];
        }
        return final_result;
        
    }
    void GetProfit(vector<int>& prices, int *pre_pro, int *post_pro){
        int min_price=INT_MAX;
        int max_pro=0;
        for(int i=0;i<prices.size();i++){
            min_price=min(prices[i],min_price);
            max_pro=max(max_pro, prices[i]-min_price);
            pre_pro[i]=max_pro;
        }
        int max_price=0;
        int min_pro=INT_MAX;
        for(int i=prices.size()-1;i>=0;i--){
            max_price=max(prices[i],max_price);
            min_pro=min(min_pro,prices[i]-max_price);
            post_pro[i]=(-min_pro);
        }
        return;
    }
};