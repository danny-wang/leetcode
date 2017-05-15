/**
204. Count Primes
Description:
Count the number of prime numbers less than a non-negative number, n.
计算2----n-1中素数的个数。 
素数又称质数，是指仅仅能被1和它自身相除的自然数。
须要注意的是1既不是素数也不是合数。
2是最小的素数。
使用推断一个数是否是素数的函数，那么这个函数须要进行一轮循环，在给定的小于n中又要进行一轮循环。所以时间复杂度是O(n^2)。
能够对推断一个数是否是素数的函数进行优化。对于数i，能够仅仅对2到√i之间的数进行推断。这样时间复杂度减少到了O(nlogn)。
可是上面的解法在leetcode中还是超时。
于是想是否存在仅仅进行一轮循环的方法。即在遍历1至n-1一次的过程中记录下素数的个数。可是后面就不知道怎么处理。
使用一个长度是n的hash表，最開始这个hash表中的全部元素都是没有被处理的，从2開始遍历，假设这个元素没有被处理，那么将素数的个数加1，然后将2*2,2*3,2*4……2* k（ 2* k < n）标记为已经被处理了的。接着開始处理3，同理将3*2,3*3,3*4…..3*m( 3 * m < n)标记为已被处理了的，接着是4，因为这个元素已经被处理。继续向后遍历。这样一直处理下去。
**/
class Solution {
public:
/*
//解法一：超时
    int countPrimes(int n) {
       int count=0;
       for(int i=2;i<=n;i++)
       {
           if(isPrime(i))
                count++;
       }
       return count;
    }

    bool isPrime(int n)
    {
        if(n==1)
            return false;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    */
解法2：
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2)
            return 0;
        bool* sig=new bool[n];
        for(int i=0;i<n;i++)
            sig[i]=true;
        int count=0;
        for(int i=2;i<n;i++){
            int muti=2;
            if(sig[i]){
                count++;
                sig[i]=false;
                while(i*muti<n){
                    sig[i*muti]=false;
                    muti++;
                }
            }
        }
        return count;
    }
};