/**
Related to question Excel Sheet Column Title
Given a column title as appear in an Excel sheet, return its corresponding column number.
For example:
    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

思路：26进制转10进制，例如AB=B*26^0+A*26^1;
**/
class Solution {
public:
    int titleToNumber(string s) {
        int result=0;
        int index=1;
        for(int i=s.size()-1;i>=0;i--){
            result=result+ int(s[i]-'A'+1)*index;
            index*=26;
        }
        return result;
    }
};