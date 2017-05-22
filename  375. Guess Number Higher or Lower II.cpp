 /**
 375. Guess Number Higher or Lower II 
 We are playing the Guess Game. The game is as follows:
I pick a number from 1 to n. You have to guess which number I picked.
Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
However, when you guess a particular number x, and you guess wrong, you pay $x. 
You win the game when you guess the number I picked.
Example:
n = 10, I pick 8.

First round:  You guess 5, I tell you that it's higher. You pay $5.
Second round: You guess 7, I tell you that it's higher. You pay $7.
Third round:  You guess 9, I tell you that it's lower. You pay $9.

Game over. 8 is the number I picked.

You end up paying $5 + $7 + $9 = $21.

Given a particular n ≥ 1, find out how much money you need to have to guarantee a win.
这题要求我们在猜测数字y未知的情况下（1~n任意一个数），要我们在最坏情况下我们支付最少的钱。也就是说要考虑所有y的情况。
我们假定选择了一个错误的数x，（1<=x<=n && x!=y ）那么就知道接下来应该从[1,x-1 ] 或者[x+1,n]中进行查找。 
假如我们已经解决了[1,x-1] 和 [x+1,n]计算问题，我们将其表示为solve(L,x-1) 和solve(x+1,n)，那么我们应该选择max(solve(L,x-1),solve(x+1,n))
这样就是求最坏情况下的损失。总的损失就是 f(x) = x + max(solve(L,x-1),solve(x+1,n))
那么将x从1~n进行遍历，取使得 f(x) 达到最小，来确定最坏情况下最小的损失
**/
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        return dp_solve(dp,1,n);
    }
    int dp_solve(vector<vector<int>> &dp ,int i, int j){
        if(i>=j)
            return 0;
        if(dp[i][j])
            return dp[i][j];
        int temp=INT_MAX;
        for(int k=i;k<=j;k++){
            if(k+max(dp_solve(dp,i,k-1),dp_solve(dp,k+1,j))<temp)
                temp=k+max(dp_solve(dp,i,k-1),dp_solve(dp,k+1,j));
        }
        dp[i][j]=temp;
        return dp[i][j];
    }
};