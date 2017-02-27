/**
Determine whether an integer is a palindrome. Do this without extra space.
思路1：将输入整数转换成倒序的一个整数，再比较转换前后的两个数是否相等，但是这样需要额外的空间开销
思路2：每次提取头尾两个数，判断它们是否相等，判断后去掉头尾两个数。
**/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        //首先计算数字x的长度
        int length=1;
        while(x/length>=10){
            length *=10;
        }
        while(x>0){
            int high_value=x/length; //最高位
            int low_value=x%10;  //最低位
            if(high_value!=low_value)  //最高位和最低位不同，肯定不是回文
                return false;
            else{
                x=(x%length)/10;  //消去最高位和最低位
                length/=100;
            }
            
        }
        return true;
        
    }
};
