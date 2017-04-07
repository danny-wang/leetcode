/**
求1+2+3+...+n 

题目描述
求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
思路：利用构造函数求解
**/
class A{
public:
    static int a;
    static int sum;
    A(){
        ++a;
        sum+=a;
    }
};
int A::a=0;
int A::sum=0;
class Solution {
public:
    int Sum_Solution(int n) {
        A* ptr=new A[n];
        int result=A::sum;
        return result;
    }
};