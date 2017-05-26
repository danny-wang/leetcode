/**
386. Lexicographical Numbers 
Given an integer n, return 1 - n in lexicographical order.
For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.

思路：
每次构造在前一个的数字上：
如果能添0不超过n尽量添0，无法添0则尝试增1，如果无法增1则抹去最后一位数字后增1 
只要进行过增1操作（包括直接增1和抹去最后一位数字以后增1），就有可能导致进位，如果进位了，就抹去末尾的所有0.
**/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n<=0)
            return {};
        if(n==1)
            return {1};
        vector<int> res;
        int temp=1;
        res.push_back(temp);
        while(1){
            if(temp*10<=n){
                temp=temp*10;
            }
            else{
                if(temp+1<=n)
                    temp=temp+1;
                else
                    temp=temp/10+1;
                while(temp%10==0)
                    temp=temp/10;
            }
            if(temp==1)
                break;
            res.push_back(temp);
        }
        return res;
        
    }
};