/**
357. Count Numbers with Unique Digits 
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.
Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
解题分析：
    题目要就就是找出 0≤ x < 10n中各位数字都不相同的数的个数。要接触这道题只需要理解：
1.设f(n)表示n位数字中各位都不相同的个数，则有countNumbersWithUniqueDigits(n)=f(1)+f(2)+……+f(n)=f(n)+countNumbersWithUniqueDigits(n-1);
2.对于f(n),由于首位不能为0，之后n--1位可以选不重复的任意数字，所以这是一个高中常见的概率题，可能性为9*9*8*……（所以可能出现的不可能超过10位);
  理解了以上两点，这道题就很好得出。
eg: f(2)=9*9+f(1)=91
注意：0-9能够组成的unique number最大只有10位，所以对于大于大于10的n，返回n=10的答案即可
**/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> res(11,0);
        res[0]=1;
        res[1]=10;
        res[2]=91;
        int index=0;
        if(n<=10)
            index=n;
        else
            index=10;
        for(int i=3;i<=index;i++){
            int temp=81;
            int count=i-2;
            int index=8;
            while(count!=0){
                temp*=index;
                count--;
                index--;
            }
            temp+=res[i-1];
            res[i]=temp;
        }
        return res[index];
        
    }
};