/**
168. Excel Sheet Column Title
Given a positive integer, return its corresponding column title as appear in an Excel sheet.
For example:
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
思路：
这是一个10进制转化26进制的问题，不停的除26取余数
要注意的是这里是从1开始而不是从0开始。所以处理的时候要先减去一
**/
class Solution {
public:
    string convertToTitle(int n) {
        int temp = n;
        stringstream ss;
        stack<char> mid_stack;
        while(temp>0){
            temp--;
            char a= (char)(temp%26+'A');
            mid_stack.push(a);
            temp=temp/26;
        }
        while(!mid_stack.empty()){
            char b=mid_stack.top();
            ss<<b;
            mid_stack.pop();
        }
        string result;
        ss>>result;
        return result;    
    }
};