/**
202. Happy Number
Write an algorithm to determine if a number is "happy".
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
Example: 19 is a happy number
  ● 12 + 92 = 82
  ● 82 + 22 = 68
  ● 62 + 82 = 100
  ● 12 + 02 + 02 = 1
思路：
循环计算每位数字的平方和，直到出现结果为1(返回true)或者重复(返回false)
结果存储在一个unordered_set 中
**/
class Solution {
public:
    bool isHappy(int n) {
        if(n<=0)
            return false;
        unordered_set<long long> results;
        long long temp=0;
        while(1){
            while(n){
                temp+=(n%10)*(n%10);
                n=n/10;
            }
            n=temp;
            if(temp==1)
                return true;
            if(results.find(temp)!=results.end())
                return false;
            else{
                results.insert(temp);
                temp=0;
                
            }
        }
        
    }
};