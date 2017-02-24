/**
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
Note that 1 is typically treated as an ugly number.
【分析】思路：根据丑陋数的定义，我们将给定数除以2、3、5，直到无法整除，也就是除以2、3、5的余数不再为0时停止。这时如果得到1，说明是所有因子都是2或3或5，如果不是1，则不是丑陋数。
**/
class Solution {
public:
    bool isUgly(int num) {
        if(num<=0)
            return false;
        while(num>=2 && num%2==0)
            num /=2;
        while(num>=3 && num%3==0)
            num /=3;
        while(num>=5 && num%5==0)
            num /=5;
        return num==1;    
    }
};