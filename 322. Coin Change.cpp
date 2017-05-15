/**
322. Coin Change
You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)
Example 2:
coins = [2], amount = 3
return -1.
Note:
You may assume that you have an infinite number of each kind of coin.

解析：这题就是很明显的DP问题，一开始想到是否可以使用贪心，后面发现是不能保证最小coin数目的，
举个例子，如果amount = 8, coins为[1, 3, 5, 6]，我们会发现，采用贪心策略得到3（6，1，1），而实际正确值为2（5，3），
之所以贪心法在这里不适用是因为贪心所作的决策并不能确保全局的最优，
如果换作这样的问题，提水，每桶都有一定量的水，怎样才能最少次数运完所有的水，这样肯定就是贪心选择最多的水。
因为每次提越多的水，最后的次数肯定最少。
coin change 其实有两种解决办法，但是思想是一样的，第一种，dp[n]为amount为n的change数目，那么我们从dp[1]开始就可以DP到dp[n]，
迭代关系式为，dp[n] = min(dp[n], dp[n-coins[m]]+1). 
还有一种方法是使用递归的方法，有可能会造成memory exceed，
递推关系为count(n,m,coins) = min(count(n,m-1,coins), count(n-coins[m],m,coins)); 
其中count表示寻找最少change的函数，n为amount，m为coins（排好序的）的下标。
**/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<0 )
            return -1;
        vector<int> times(amount+1,INT_MAX-10);
        times[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(i>=coins[j])
                    times[i]=min(times[i],times[i-coins[j]]+1);
            }
        }
        if(times[amount]==INT_MAX-10)
            return -1;
        else
            return times[amount];
    }
};