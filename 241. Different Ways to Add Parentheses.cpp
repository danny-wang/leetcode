/**
241. Different Ways to Add Parentheses
Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.

Example 1
Input: "2-1-1".
((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]

Example 2
Input: "2*3-4*5"
(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]

这道题主要思想是Divide and Conquer 分治法
对于一个表达式 a - b, a与b均为表达式，计算a - b的结果 我们需要先知道a的结果与b的结果。对于知道加parentheses的题，只要对表达中的每一个运算符都做这样的操作并递归，就可以得出所有可能结果，希望下面的例子可以帮助理解
                        2 * 3 - 4 * 5
                            /        \
              2 * (3 - 4 * 5)        ...
                        /     \
              (3 - 4 ) * 5     3 - (4 * 5)
               /    \
               3     4
**/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        for(int i=0;i<input.size();i++){
            char c=input[i];
            if(input[i]=='+' || input[i]=='-' || input[i]=='*'){
                vector<int> l,r;
                l=diffWaysToCompute(input.substr(0,i));
                r=diffWaysToCompute(input.substr(i+1));
                for(int i=0;i<l.size();i++){
                    for(int j=0;j<r.size();j++){
                        if(c=='+')
                            result.push_back(l[i]+r[j]);
                        else if(c=='-')
                            result.push_back(l[i]-r[j]);
                        else if(c=='*')
                            result.push_back(l[i]*r[j]);
                    }
                }
            }
        }
        if(result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};