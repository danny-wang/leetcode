/**
斐波那契数列
题目描述
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
n<=39
**/
class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0)
            return 0;
        if(n==1 || n==2)
            return 1;
		    int a=1;
        int b=1;
        for(int i=3;i<=n;i++){
            int old_a=a;
            a=b;
            b=old_a+b;
        }
        return b;
    }
};
