/**
矩形覆盖 
题目描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？ 
思路：还是一个非伯纳且数列问题  
**/
class Solution {
public:
    int rectCover(int number) {
		int result[3]={0,1,2};
        if(number<=2)
            return result[number];
        long a=1;
        long b=2;
        for(int n=3;n<=number;n++){
            long old_a=a;
            a=b;
            b = b+old_a;
        }
        return (int)b;
    }
};
