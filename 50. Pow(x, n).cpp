/**
50. Pow(x, n)
Implement pow(x, n).
思路：
二分，复杂度为O(logn)
递归方法
**/
double helper(double x,int n){
        if(n==0)
            return 1;
        if(n==1)
            return x;
        if((n&1)==1){
            double temp=helper(x,n>>1);
            return temp*temp*x;
        }
        else{
            double temp=helper(x,n>>1);
            return temp*temp;
        }
    }
当abs(n)很大的时候调用链太深，会溢出。
/**
思路2：
位运算。就是把n看成是以2为基的位构成的，因此每一位是对应x的一个幂数，然后迭代直到n到最高位。
比如说第一位对应x，第二位对应x*x,第三位对应 x^4,...,第k位对应x^(2^(k-1)),可以看出后面一位对应的数等于前面一位对应数的平方，
所以可以进行迭代。因为迭代次数等于n的位数， 所以算法的时间复杂度是O(logn)。代码如下：
**/
class Solution {
public:
    double myPow(double x, int n) {
        if(x>=-0.000001 && x<=0.000001 && n<0)
            return -1;
        if(x>=-0.000001 && x<=0.000001 && n>=0)
            return 0;
        bool n_is_negative = (n<0? true:false);
        bool result_is_negative= (x<0 && (abs(n)&1)==1);
        //double result=helper(x,abs(n));
        double result=1;
        if(abs(n)==0)
            result=1;
        if(abs(n)==1)
            result=abs(x);
        long long j=abs((long long)n);
        if(j>1){
        while(j){   //位运算
            if(j&1)
                result*=abs(x);
            x=x*x;
            j=j>>1;
        }
        }
        if(n_is_negative)
            result=1/result;
        if(result_is_negative)
            result=(0-result);
        return result;
    }   
    
    
    
    
};