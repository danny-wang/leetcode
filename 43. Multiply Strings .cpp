/*
43. Multiply Strings 

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
Note:
  1. The length of both num1 and num2 is < 110.
  2. Both num1 and num2 contains only digits 0-9.
  3. Both num1 and num2 does not contain any leading zero.
  4. You must not use any built-in BigInteger library or convert the inputs to integer directly.

这道题的要求是计算大数乘法。其中大数是以字符串的形式表示，任意大，非负，返回结果以字符串形式。
这道题其实就是模拟整数乘法。
假设两个整数的长度分别为了l1和l2，则其最后结果长度为l1+l2（最后有进位）或者l1+l2-1（最后没有有进位）。
因此，可以先用长度为l1+l2的数组记录结果，最后再转成字符串。
进行乘法的时候，先把各个位的相乘结果对应累加起来，即第1个整数的第i位（低位到高位）和第2个整数的第j位（低位到高位）相乘的结果应该存放在数组的i+j位。然后再统一处理进位。
最后再将数组转成字符串前，需要跳过前面的零。如果结果只有0，则只返回0。
时间复杂度：O(l1*l2)（l1和l2分别为两个整数长度）
空间复杂度：O(l1+l2)
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty())
            return 0;
        int num1_size=num1.size();
        int num2_size=num2.size();
        vector<int> medium_res(num1_size+num2_size,0); //结果的位数要么是num1_size+num2_size(有进位)，要么是num1_size+num2_size-1(没有进位)
        for(int i=0; i<num1_size;i++){
            for(int j=0; j<num2_size;j++){
                medium_res[i+j]+=((num1[num1_size-i-1]-'0')*(num2[num2_size-j-1]-'0'));
            }
        }
        int carry=0;
        for(int i=0;i<num1_size+num2_size;i++){
            int temp=medium_res[i]+carry;
            medium_res[i]=temp%10;
            carry=temp/10;
        }
        int indice=num1_size+num2_size-1;
        while(indice>=0&&medium_res[indice]==0)
            indice--;
        string result="";
        for(;indice>=0;indice--)
            result+=(medium_res[indice]+'0');
        if(result.empty())
            return "0";
        else
            return result;
    }
};