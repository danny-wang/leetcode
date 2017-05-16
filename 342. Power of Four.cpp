/*
342. Power of Four 
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.
Example:
Given num = 16, return true. Given num = 5, return false.
Follow up: Could you solve it without loops/recursion?
思路1：不停的除以4，直到商等于1，在此期间如果除以4的余数不为0，就返回false
注意：4^0=1，所以1要单独处理
**/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        if(num==1)
            return true;
        while(num!=1){
            if(num%4!=0)
                return false;
            num=num/4;
        }
        return true;
    }
};
/**
思路2：要判断是不是4的幂指数，那么只有以下情况：
(2^2)^0	1
(2^2)^1	100	
(2^2)^2	10000
(2^2)^3	1000000
(2^2)^4	100000000
(2^2)^5	10000000000
.......
所以只能有一位为1，而且1只能出现在奇数位上。那么先判断是否只有一位为1，如果是的话，判断1是否出现在奇数位上。时间复杂度为O（1）。
注意：判断只有1位为1可以利用a&(a-1)==0
但是这种思路依然会用到循环。在进一步思考，可得思路3
**/
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        if((num&(num-1))==0){ //判断是否只有一位为1
            int index=0;
            while(index<=30){
                if((num>>index)&1)
                    return true;
                index+=2;
            }
            return false;
        }
        else
            return false;
    }
};
//思路三：一个数 num 如果是 4 的 N 次方必然也是 2 的 N 次方。所以可以先判断 num 是否是 2 的 N 次方（也就是只有一位为1）。
//然后再将 2 的 N 次方中那些不是 4 的 N 次方的数去掉。因此就有了下面的代码。
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        if((num&(num-1))==0){
            if(num&0x55555555)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};