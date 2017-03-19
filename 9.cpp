/**
变态跳台阶
题目描述
一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
思路： 跳到3级台阶的跳发就等于：跳到2级台阶的跳法+调到1级台阶的跳法+1（直接跳上来）
**/
class Solution {
public:
    int jumpFloorII(int number) {
		if(number<=0)
            return 0;
        if(number==1)
            return 1;
        int result=1;
        for(int i=2;i<=number;i++){
            result*=2;
        }
        return result;
    }
};
