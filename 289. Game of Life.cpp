/**
289. Game of Life
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
  1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
  2. Any live cell with two or three live neighbors lives on to the next generation.
  3. Any live cell with more than three live neighbors dies, as if by over-population..
  4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.
Follow up: 
  1. Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
  2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

提示：
由于题目中要求所有点的状态需要一次性发生改变，而且不用额外的空间，这是本题的最大难点。
既然需要“就地解决”，我们不妨分析一下borad的特性：board上的元素有两种状态，生（1）和死（0）。这两种状态存在了一个int型里面。所以我们可以有效利用除最低位的其它位，去保存更新后的状态，这样就不需要有额外的空间了。
具体而言，我们可以用最低位表示当前状态，次低位表示更新后状态：
  ● 00(0)：表示当前是死，更新后是死；
  ● 01(1)：表示当前是生，更新后是死；
  ● 10(2)：表示当前是死，更新后是生；
  ● 11(3)：表示当前是神，更新后是生。
**/
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0 || board[0].size()==0)
            return;
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                int count=GetLiveNeighbor(board,i,j);
                if(board[i][j]==0){
                    if(count==3)
                        board[i][j]=2;
                }
                else{
                    if(count<2)
                        board[i][j]=1;
                    if(count==2 || count==3)
                        board[i][j]=3;
                    else
                        board[i][j]=1;
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                board[i][j]=(board[i][j]>>1);   
            }
        }
    }
    int GetLiveNeighbor(vector<vector<int>>& board, int x,int y){
        int count=0;
        for(int i=x-1;i<=x+1;i++){
            for(int j=y-1;j<=y+1;j++){
                if(i<0 || j<0 ||i>=board.size()|| j>=board[0].size()||((i==x) && (j==y)))
                    continue;
                else{
                    if((board[i][j]&1)==1)
                        count++;
                }
            }
        }
        return count;
    }
};