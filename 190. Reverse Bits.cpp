/**
190. Reverse Bits
Reverse bits of a given 32 bits unsigned integer.
For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
Follow up:
If this function is called many times, how would you optimize it?
Related problem: Reverse Integer

分析如下：
类似revers integer的思路， 注意比特运算。
比如value = (value<<1 )|((n&mask)>>i);  这句后的n&mask会逐渐取得n的第0，1，2，, , , 31位的数，取得之后，还需要把它加到逐渐滚动的value上去。
我采用的是模拟reverse integer的方法，把每次取得的n&mask的数表达为第0位的数之后再添加到value上去。
**/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result=0;
        for(int i=0;i<32;i++)
            result=(result<<1) + ((n>>i)&1);
        return result;
    }
};