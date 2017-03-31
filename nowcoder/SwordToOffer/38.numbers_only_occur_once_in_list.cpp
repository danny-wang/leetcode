/**
数组中只出现一次的数字

题目描述
一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
思路：任何数字疑惑它自己都等于0。也就是说，如果我们从头到尾依次异或数组中的每一个值，那么最终的结果刚好是那个出现一次的数字。
试着将原数组分解为两个，每个包含一个只出现一次的数字，而其他数字都成对出现两次。
注意：也可以直接写  int signal=result_exclusive_or^(result_exclusive_or&(result_exclusive_or-1))
原因：把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0。  接着和原数做异或操作，即是除了最右边的一个1，其他位全部变成0
**/
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int result_exclusive_or=0;
        for(auto i : data){
            result_exclusive_or^=i;
        }
        int index=0;
        while((result_exclusive_or& 0x1)==0x0){
            result_exclusive_or>>=1;
            index++;
        }
        int signal=0x1<<index;
        vector<int> left,right;
        for(auto i : data){
            if(i&signal)
                left.push_back(i);
            else
                right.push_back(i);
        }
        int a=0,b=0;
        for(auto i:left){
            a^=i;
        }
        for(auto i : right){
            b^=i;
        }
        *num1=a;
        *num2=b;
        return;
    }
};