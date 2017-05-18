 /**
 367. Valid Perfect Square 
 Given a positive integer num, write a function which returns True if num is a perfect square else False.
Note: Do not use any built-in library function such as sqrt.
Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False
思路1：二分查找
**/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<0)
            return false;
        if(num==1)
            return true;
        int left=0;
        int right=(num>>1);
        while(left<=right){
            //注意mid*mid之后可能会溢出，所以要用long long类型来存储
            long long mid=(left+((right-left)>>1));
            if(mid*mid==num)
                return true;
            else if(mid*mid<num)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};
/**
思路2：
完全平方数是一系列奇数之和，例如：
1 = 1
4 = 1 + 3
9 = 1 + 3 + 5
16 = 1 + 3 + 5 + 7
25 = 1 + 3 + 5 + 7 + 9
36 = 1 + 3 + 5 + 7 + 9 + 11
....
1+3+...+(2n-1) = (2n-1 + 1)n/2 = n*n
**/
public class Solution {
    public boolean isPerfectSquare(int num) {
        int i = 1;
        while (num > 0) {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
}
