/**
279. Perfect Squares
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) 
which sum to n.
For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

分析
完美平方数，给定任意数n，它可表示为多个平方数（如1,4,9,16…）的和，求出表示出任意数n所需的平方数的最少个数。
考察动态规划， 
如果一个数x可以表示为一个任意数a加上一个平方数b∗b，也就是x=a+b∗b，那么能组成这个数x最少的平方数个数，就是能组成a最少的平方数个数加上1（因为b∗b已经是平方数了）。
**/
class Solution {
public:
    /* 如果一个数x可以表示为一个任意数a加上一个平方数bｘb，也就是x = a + bｘb，
     * 那么能组成这个数x最少的平方数个数，就是能组成a最少的平方数个数加上1（因为b*b已经是平方数了）。
     */
    int numSquares(int n) {
        // 将所有非平方数的结果置最大，保证之后比较的时候不被选中
        vector<int> nums(n + 1, INT_MAX);

        // 将所有整平方数的结果置1
        for (int i = 0; i*i <= n; ++i)
        {
            nums[i*i] = 1;
        }//for

        // 从小到大找任意数a
        for (int a = 0; a <= n; ++a)
        {
            // 从小到大找平方数b*b
            for (int b = 0; a + b*b <= n; ++b)
            {
                // 因为a+b*b可能本身就是平方数，所以我们要取两个中较小的
                nums[a + b*b] = min(nums[a] + 1, nums[a + b*b]);
            }//for
        }//for
        return nums[n];
    }
};