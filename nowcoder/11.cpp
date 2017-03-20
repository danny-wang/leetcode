/**
二进制中1的个数 
题目描述
输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。 
**/
class Solution {
public:
     int  NumberOf1(int n) {
         int a=1;
         int count=0;
         while(a){
             if(n & a){  //该位为1
                 count++;
             }
             a=a<<1;
         }
         return count;
     }
};
