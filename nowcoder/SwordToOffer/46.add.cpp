/**
不用加减乘除做加法 

题目描述
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
思路：利用与运算和异或运算，与运算求进位，异或运算求等于1的位
**/
class Solution {
public:
    int Add(int num1, int num2)
    {
        long long a=num1;
        long long  b=num2;
        
	while(b!=0){
            long long  temp_a=a^b;
            long long  temp_b=((a&b)<<1);
            a=temp_a;
            b=temp_b;
        }
        return a;
    }
};