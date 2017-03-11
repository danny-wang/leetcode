/**
Given an integer n, return the number of trailing zeroes in n!.
Note: Your solution should be in logarithmic time complexity.
思路：首先想到的是先求n的阶乘，然后通过每次除以10计算后面有几个0，但是当计算到30！的时候就溢出了，而且时间复杂度也不是对数的。
代码如下：
**/
class Solution {
public:
    int trailingZeroes(int n) {
        if(n<0)
            return 0;
        unsigned long long  fact= factorial(n);
        cout<<fact<<endl;
        int result=0;
        while(fact%10==0){
            result++;
            fact=fact/10;
        }
        return result;
    }
    unsigned long long  factorial(int a){
        if(a==0)
            return 1;
        else if(a==1)
            return 1;
        else
            return a*factorial(a-1);
    }
};
/**
正确思路：
对n!做质因数分解n!=2x*3y*5z*...
显然0的个数等于min(x,z)，并且min(x,z)==z
证明：
对于阶乘而言，也就是1*2*3*...*n
[n/k]代表1~n中能被k整除的个数
那么很显然
[n/2] > [n/5] (左边是逢2增1，右边是逢5增1)
[n/2^2] > [n/5^2](左边是逢4增1，右边是逢25增1)
……
[n/2^p] > [n/5^p](左边是逢2^p增1，右边是逢5^p增1)
随着幂次p的上升，出现2^p的概率会远大于出现5^p的概率。
因此左边的加和一定大于右边的加和，也就是n!质因数分解中，2的次幂一定大于5的次幂

思路已经清楚，下面就是一些具体细节，这个细节还是很重要的。
我在最开始的时候就想错了，直接返回了n / 5，但是看到题目中有要求需要用O(logn)的时间复杂度，就能够想到应该没这么简单。举连个例子：
例1
n=15。那么在15! 中 有3个5(来自其中的5, 10, 15)， 所以计算n/5就可以。
例2
n=25。与例1相同，计算n/5，可以得到5个5，分别来自其中的5, 10, 15, 20, 25，但是在25中其实是包含2个5的，这一点需要注意。
所以除了计算n/5， 还要计算n/5/5, n/5/5/5, n/5/5/5/5, ..., n/5/5/5,,,/5直到商为0，然后就和，就是最后的结果
**/
class Solution {
public:
    int trailingZeroes(int n) {
        int result=0;
        while(n){
            result+=n/5;
            n=n/5;
        }
        return result;
    }
};
