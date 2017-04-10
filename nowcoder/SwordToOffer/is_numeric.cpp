/**
表示数值的字符串 

题目描述
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
思路：
这里是判断是否一个字符串可以转为数值。从测试用例来看，表示的字符串有三类：整数、浮点数和科学计数法表示的数值。
那么基本思路就是根据这三种类型进行判断：对于整数比较容易判断，只要字符串没有出现非0到9的字符，就可以跳过，否则返回错误；
对于浮点数，因为可能会出现多个小数点的情况，所以如果展开判断会很复杂，只要考虑是正确的情况就可以——即只出现一个小数点的情况，
至于小数点后面的字符串则与判断整数是一样得思路；对于科学计数法表示的数值，无非就两类一种是e一种是E，
至于e或者E后面的字符串的判断也是与整数的判断是一样的。而且，注意到，如果e或者E后面没有数字的话是不被允许的。
**/
class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string==nullptr)
            return false;
        char* ptr=string;
        if(*ptr=='+' || *ptr=='-')
            ptr++;
        if(*ptr=='\0')
            return false;
        bool has_point=false;
        while(*ptr!='\0'){
            if(*ptr>='0'&&*ptr<='9'){
                ptr++;
                continue;
            }
            if(*ptr=='.'){
                if(has_point)
                    return false;
                else{
                    has_point=true;
                    ptr++;
                    continue;
                }
            }
            if(*ptr=='e'||*ptr=='E')
                return IsExponential(ptr+1);
            else
                return false;
        }
        return true;
    }
    bool IsExponential(char* str){
        char* ptr=str;
        if(*ptr=='+' || *ptr=='-')
            ptr++;
        if(*ptr=='\0')
            return false;
         while(*ptr!='\0'){
             if(*ptr>='0'&&*ptr<='9'){
                ptr++;
                continue;
             }
             else
                 return false;
         }
        return true;
    }

};