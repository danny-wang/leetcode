390. Elimination Game 
There is a list of sorted integers from 1 to n. Starting from left to right, remove the first number and every other number afterward until you reach the end of the list.
Repeat the previous step again, but this time from right to left, remove the right most number and every other number from the remaining numbers.
We keep repeating the steps again, alternating left to right and right to left, until a single number remains.
Find the last number that remains starting with a list of length n.
Example:
Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6 

思路：
这道题首先可以推出一个规律：
1、无论是1还是2，若当前序列长度为k，那么下一轮一定只剩k/2【整除】个
然后我们来说下这个递推的式子：
1、一开始不是1,2,3,4,5,6..n 对吧？第一轮结束剩下2，4，6，8，10….2*(n/2) 等于2*(1,2,3,4…n/2),看着这个序列，是否觉得和一开始的问题很像，对吧，但是似乎有点不一样？
2、对于下一轮而言，虽然是1,2,3,4…,n/2,但是顺序是相反的消除？那既然这样，我们转变成n/2,…,4,3,2,1不就好了，所以我们还是按照1的方式求1，2，3，4…n/2但是对于结果要n/2 + 1 - lastremain掉不就好了？
如
n = 9,
1 2 3 4 5 6 7 8 9(123456789)
2 4 6 8(折半反向后是8642，按照正序的去除规则，去除了8，4，得到62)
2 6(按照上一步反向26，去除第一位2，得到最终结果6）
6

注意：从后往前第k个，也就是从前往后第n+1-k个。这也就是n/2 + 1 - lastremain的原因
eg:    1 2 3 4 5
4是从后往前第2个，也就是从前往后第5+1-2=4个。



思路
After first elimination, all the numbers left are even numbers.
Divide by 2, we get a continuous new sequence from 1 to n / 2.
For this sequence we start from right to left as the first elimination.
Then the original result should be two times the mirroring result of lastRemaining(n / 2).

public class Solution {
    public int lastRemaining(int n) {
        //将其镜像对折为一个子问题，当前状态可以推出的下一个状态的结果，但是相反
        return n==1?1:2*(n/2 + 1 - lastRemaining(n/2));

    }
}