/**
Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
思路：丑数一定是前面某一个数乘以2，3或者5，其中大于之前出现的所有数的最小值，所以我们选中一个值得时候就更新它。
We have an array k of first n ugly number. We only know, at the beginning, the first one, which is 1. Then
k[1] = min( k[0]x2, k[0]x3, k[0]x5). The answer is k[0]x2. So we move 2's pointer to 1. Then we test:
k[2] = min( k[1]x2, k[0]x3, k[0]x5). And so on. Be careful about the cases such as 6, in which we need to forward both pointers of 2 and 3.
**/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==0)
            return 0;
        vector<int> ugly_num={1};
        int index_2=0,index_3=0,index_5=0;
        for(int i = 1;i < n; i++){
            int temp=min_of_three(ugly_num[index_2]*2, ugly_num[index_3]*3, ugly_num[index_5]*5);  //pointer of 2,3,5
            ugly_num.push_back(temp);
            if(temp==ugly_num[index_2]*2)
                index_2++;
            if(temp==ugly_num[index_3]*3)
                index_3++;
            if(temp==ugly_num[index_5]*5)
                index_5++;
        }
        return ugly_num[n-1];
    }
    int min_of_three(int a, int b, int c){  //三个数中的最小值
        int result=min(a,b);
        result=min(result,c);
        return result;
    }
};
