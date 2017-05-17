/**
344. Reverse String 
Write a function that takes a string as input and returns the string reversed.
Example:
Given s = "hello", return "olleh".
思路：classic方法头尾交换
16ns
**/
class Solution {
public:
    string reverseString(string s) {
        if(s.empty())
            return s;
        string temp(s);
        auto ite_l=temp.begin();
        auto ite_r=temp.end()-1;
        while(ite_l<ite_r){
            char a=*(ite_l);
            *(ite_l)=*(ite_r);
            *(ite_r)=a;
            ite_l++;
            ite_r--;
        }
        return temp;
    }
};
//9ns
class Solution {
public:
    string reverseString(string s) {
        if(s.empty())
            return s;
        string temp(s);
        auto ite_l=temp.begin();
        auto ite_r=temp.end()-1;
        while(ite_l<ite_r){
            *(ite_l)=*(ite_l)^*(ite_r);
            *(ite_r)=*(ite_l)^*(ite_r);
            *(ite_l)=*(ite_l)^*(ite_r);
            ite_l++;
            ite_r--;
        }
        return temp;
    }
};
/**
P.S.最后关于swap交换元素介绍两个思路：
1.tmp中间变量，最熟悉的方法。
　　tmp=i;
　　i=tmp;
　　j=tmp;
2.bit的按位抑或^原理，即m^m=0，0^m=m。
　　m=m^n;
　　n=m^n;                 等价于　　　　　　n=m^n^n=m;
　　m=m^n;　　　　　　　　　　　　　 m=m^n^m=n;
后者最交换速度更快
异或运算的性质：
性质
1、交换律
2、结合律（即(a^b)^c == a^(b^c)）
3、对于任何数x，都有x^x=0，x^0=x
4、自反性 A XOR B XOR B = A xor  0 = A
**/