/**
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2

Note:
For a given n, a gray code sequence is not uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

分析如下:
手动地写写n=3时候的情况，会发现。n=3的结果如下:
000
001
011
010  ↑
--------
110  ↓
111
101
100
可看成是上下对称的2部分。上半部分是n=2时候的结果再在最高位加"0"的结果。下半部分是n=2时候的结果逆序之后再在最高位加"1"的结果。这样代码就很好写了。
代码：
**/
class Solution {
public:
    vector<int> grayCode(int n) {
        if(n==0)
            return {0};
        if(n==1)
            return {0,1};
        vector<int> pre_vec=grayCode(n-1);
        vector<int> cur_vec(pre_vec);
        for(int i= pre_vec.size()-1;i>=0;i--){
             cur_vec.push_back((1<<(n-1))+pre_vec[i]);
        }
           
        return cur_vec;
    }
};
