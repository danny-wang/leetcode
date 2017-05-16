/**
 343. Integer Break 
 Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
Note: You may assume that n is not less than 2 and not larger than 58.
题意：给一个n(n>=2),求相加等于n且乘积最大的一组整数的积。
题解：
这其实就是一道高中数学题，但是leetcode上的数据比较水，导致完全不用数学推导的O(n2)的dp也可以过。
解法一（纯dp）：
令dp[n]为n对应的最大积。
那么递推方程就是：dp[n]=max(i*dp[n-i],i*(n-i))(其中i从1到n-1)。
边界:dp[2]=1;
时间复杂度：O(n2)
**/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> mid(n+1,-1);
        mid[2]=1;
        mid[3]=2;
        for(int i=3;i<=n;i++){
            for(int j=1;j<i;j++){
                mid[i]=max(mid[i],max(j*mid[i-j],j*(i-j)));
            }
        }
        return mid[n];
        
    }
};
/**
解法2：http://blog.csdn.net/liyuanbhu/article/details/51198124
作为一道编程题，这道题还是很简单的。简单的观察就能知道拆出足够多的 3 就能使得乘积最大。
这道题的难点其实在于证明为什么拆出足够多的 3 就能使得乘积最大。下面我就试着证明一下。
首先证明拆出的因子大于 4 是不行的。设 x 是一个因子，x>4，那么可以将这个因子再拆成两个因子 x−2 和 2，易证 (x−2)×2>x。所以不能有大于 4 的因子。
4 这个因子也是可有可无的，4=2+2，4=2×2。因此 4 这个因子可以用两个 2 代替。
除非没有别的因子可用，1 也不能选作因子。一个数 x 当它大于 3 时，有 (x−2)×2>(x−1)×1。
这样呢，就只剩下 2 和 3 这两个因子可以选了。下面再证明 3 比 2 好。

再多说一句，如果拆出的因子不限于整数的话，可以证明e=2.718… 是最佳的选择。感兴趣的可以试着证明一下。
**/
int integerBreak(int n)
{
    if(n == 2) return 1;
    if(n == 3) return 2;
    int ret = 1;
    while( n>4 )
    {
        ret *= 3;
        n -= 3;
    }
    return ret * n;
}