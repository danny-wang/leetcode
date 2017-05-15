/**
227. Basic Calculator II
Implement a basic calculator to evaluate a simple expression string.
The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
You may assume that the given expression is always valid.
Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5

Note: Do not use the eval built-in library function.

思路：1) 在遍历字符串时计算乘除；2) 为方便使用stack，将减法转换为加分，使加减法可从右往左计算。
**/
class Solution {
public:
    int calculate(string s) {
        int size=s.size();
        int num=0;
        char sig='+';
        for(int i=0;i<size;i++){
            if(s[i]>='0' && s[i]<='9'){
                num=num*10+(s[i]-'0');
            }
            if(s[i]=='+' ||s[i]=='-' ||s[i]=='*' ||s[i]=='/' ||i==size-1 ){
                switch(sig){
                    case '+' : sta.push(num);break;
                    case '-' : sta.push(0-(long long)num);break;
                    case '*' : {long long temp=sta.top();
                                sta.pop();
                                sta.push(temp*num);
                                break;}
                    case '/' : { long long temp=sta.top();
                                sta.pop();
                                sta.push(temp/num);
                                break;}
                    default : sta.push(num);break;
                }
                num=0;
                sig=s[i];
                continue;
            }
            if(s[i]==' ')
                continue;
        }
        if(sta.empty())
            return 0;
        int result=0;
        while(!sta.empty()){
            int temp=sta.top();
            result+=temp;
            sta.pop();
        }
        return result;
    }
private:
    stack<long long> sta;
};