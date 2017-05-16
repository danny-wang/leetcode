/**
338. Counting Bits 
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
Example:
For num = 5 you should return [0,1,1,2,1,2].
Follow up:
  ● It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
  ● Space complexity should be O(n).
  ● Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
思路1：
对于每一个数计算它1的个数  注意a&(a-1)会把最右边的一个1变成0，统计a变成0之前需要几步即可。时间复杂度是O(n*sizeof(integer))
**/
class Solution {
public:
    vector<int> countBits(int num) {
        if(num<0)
            return {};
        vector<int> res;
        for(int i=0;i<=num;i++){
            int count=0;
            int temp=i;
            while(temp!=0){
                count++;
                temp=(temp&(temp-1));
            }
            res.push_back(count);
        }
        return res;
    }
};
/**
思路2：
主要是观察到
1
10
11
100
101
110
111
1000
上述观察到1->10/11  10->100/101 11->110/111
即循环地在每个数后面加0、1可得接下来的数字。因此第i位就是第i/2位+（i%2）的值。
**/
class Solution {
public:
    vector<int> countBits(int num) {
        if(num<0)
            return {};
        vector<int> res;
        res.push_back(0);
        for(int i=1;i<=num;i++){
            res.push_back((res[i>>1])+i%2);
        }
        return res;
    }
};