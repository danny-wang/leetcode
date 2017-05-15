/**
130. Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
For example,
X X X X
X O O X
X X O X
X O X X

After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

思路：
只有边界上'O'的位置组成的片区不会被'X'包围。
因此先对边界上的'O'遍历之后暂存为'S'。
非'S'的'O'即被'X'包围了。
可以用深度优先遍历和广度优先遍历
**/
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0 || board[0].size()==0)
            return;
        int rows=board.size();
        int cols=board[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 || i==rows-1 ||j==0|| j==cols-1){
                    if(board[i][j]=='O')
                        helper(board,make_pair(i,j),rows,cols);
                }
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(board[i][j]=='S')
                    board[i][j]='O';
            }
        }
    }
    void helper(vector<vector<char>>& board, pair<int,int> point,int rows, int cols){
        stack<pair<int,int>> mid;
        mid.push(point);
        board[point.first][point.second]='S';
        while(!mid.empty()){
            point=mid.top();
            mid.pop();
            if(point.first>0&&board[point.first-1][point.second]=='O'){
                mid.push(make_pair(point.first-1,point.second));
                board[point.first-1][point.second]='S';
            }
            if(point.first<rows-1&&board[point.first+1][point.second]=='O'){
                mid.push(make_pair(point.first+1,point.second));
                board[point.first+1][point.second]='S';
            }
            if(point.second>0&&board[point.first][point.second-1]=='O'){
                mid.push(make_pair(point.first,point.second-1));
                board[point.first][point.second-1]='S';
            }
            if(point.second<cols-1&&board[point.first][point.second+1]=='O'){
                mid.push(make_pair(point.first,point.second+1));
                board[point.first][point.second+1]='S';
            }
            
        }
    }
};