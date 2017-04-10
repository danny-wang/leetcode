/**
把字符串转换成整数 
题目描述
将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。 数值为0或者字符串不是一个合法的数值则返回0
输入描述:
输入一个字符串,包括数字字母符号,可以为空


输出描述:
如果是合法的数值表达则返回该数字，否则返回0

输入例子:
+2147483647
    1a33

输出例子:
2147483647
    0
思路：注意‘+’和“-”，还有判断字符是否异常
**/
class Solution {
public:
    int StrToInt(string str) {
        if(str.size()==0)
            return 0;
        bool is_positive=true;
        string::const_iterator ite=str.begin();
        if(str[0]=='-'){
            ite++;
            is_positive=false;
        }
        if(str[0]=='+'){
            ite++;
            is_positive=true;
        }
        long long  res_without_sig=0;
       	while(ite!=str.end()){
            if(*ite<='9'&& *ite>='0'){
                res_without_sig=res_without_sig*10+(*ite-'0');
                ite++;
            }
            else
                return 0;
        }
        if(is_positive)
            return res_without_sig;
        else
            return -res_without_sig;
    }
};