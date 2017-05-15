319. Bulb Switcher
There are n bulbs that are initially off. You first turn on all the bulbs.
Then, you turn off every second bulb. 
On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on).
For the ith round, you toggle every i bulb. For the nth round, you only toggle the last bulb. 
Find how many bulbs are on after n rounds.
Example:
Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.

解析：
返回值其实就是n开方后向下取整的得数。
对于每个数字来说，除了平方数，都有偶数个因数。
例如：
如6有4个因数：1×6=6，2×3=6
如60有12个因数：1×60=60，2×30=60，3×20=60，4×15=60，5×12=60，6×10=60
可以看出，非平方数的因数总是成对出现的，只有平方数的因数才是奇数，因为平方数除平方根外，其他的因数都是成对出现的！
对于当前的开关灯泡问题，可知到最后处在平方数位置的灯泡一定是开启的，其他位置的灯泡一定是关闭的。
而要计算一个数之下有多少小于或等于它的平方数，使用一个开平方用的函数就可以了.

class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};