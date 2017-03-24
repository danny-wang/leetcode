/**
数组中出现次数超过一半的数字
题目描述
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

思路：

1，如果对数组排序，那么n/2对应的数一定是超过一半的数字（前提是存在这个数字），即长度为n的数组中第n/2大的数字

2，根据数组特点，数组中一个数组出现的次数超过数组长度的一半，即它出现的次数比其他所有数字出现次数的和还要多。

因此，遍历数组时，保留两个值，一个是数组中的一个数字，一个是次数。

当我们遍历到下一个数字的时候，如果下一个数字和我们之前保存的数字相同，则次数加1,；如果下一个数字和我们之前保存的数字不同，则次数减1,。
如果次数为0，我们需要保存下一个数字，并把数字设为1,。由于我们要找的数字出现的次数比其他所有数字出现的次数还要多，
那么要找的数字肯定是最后一次把次数设为1时对应的数字。

注意：最后一定要检查结果是否真的是数组中超过一半的数字，因为有可能数组中没有任何一个元素超过一半。
**/
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        int val=numbers[0];
        int count=1;
        for(int i=1;i<numbers.size();i++){
            if(numbers[i]==val)
                count++;
            if(numbers[i]!=val){
                count--;
                if(count==0){
                    val=numbers[i];
                    count=1;
                }
            }
        }
        if(CheckMoreThanHalf(numbers, val))
            return val;
        else
            return 0;
        
    }
    bool CheckMoreThanHalf(vector<int>& numbers,int result){
        int count=0;
        for(auto i:numbers){
            if(i==result)
                count++;
        }
        if(count>(numbers.size()>>1))
            return true;
        else
            return false;
    }
};