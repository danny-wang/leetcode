/**
150. Evaluate Reverse Polish Notation
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

逆波兰计算，大话数据结构中讲到过，用一个栈来实现后缀表达式的计算。

思路：从左到右遍历表达式的每个数字和字符，遇到数字就进栈，遇到符号，就将栈顶的两个数字取出（注意第一次取出的是右操作数，第二次取出的栈顶数字是左操作数），进行运算，将运算结果压栈，一直到最终获得计算结果（最终的栈顶数字）。
**/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.empty())
            return 0;
        stack<int> s;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+" || tokens[i]=="-" ||tokens[i]=="*"||tokens[i]=="/"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                if(tokens[i]=="+")
                    s.push(b+a);
                else if(tokens[i]=="-")
                    s.push(b-a);
                else if(tokens[i]=="*")
                    s.push(b*a);
                else 
                    s.push(b/a);
            }
            else{
                s.push(atoi(tokens[i].c_str()));
            }
        }
        return s.top();
    }
};