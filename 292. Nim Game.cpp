/**
292. Nim Game
You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner.
 You will take the first turn to remove the stones.
Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.
For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.
思路：
    因为只能移动1、2、3块石头，所以只要对手最后拿的时候剩下4块石头，那无论他拿走几块石头，我都可以全部拿完，而之前每次拿石头，不管对手拿几个，我都以凑够4个为目标拿。所以在我第一个拿石头的前提下，只要总数除以4有余数，
    我第一次拿余数即可保证对手最后一次拿之前只剩下4颗石头。
**/
class Solution {
public:
    bool canWinNim(int n) {
        if(n<=0)
            return false;
        if(n%4==0)
            return false;
        else
            return true;
    }
};