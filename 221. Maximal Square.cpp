/**
221. Maximal Square
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
For example, given the following matrix:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Return 4.

思路：动态规划：
A[i][j]表示的就是以(i,j)为右下角的最大的正方形的边长
如果matrix[i][j]为1，那么A[i][j]=min(A[i-1][j-1],A[i-1][j],A[i][j-1])+1；如果matrix[i][j]为0，那么A[i][j]为0。
最大的正方形边长为max{A[i][j]}。
此时时间复杂程度是O(M*N)，空间复杂程度是O(M*N)。
**/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty())
            return 0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        int max_size=0;
        vector<vector<int>> v_size(rows,vector<int>(cols,0));
        for(int i=0;i<cols;i++){
            if(matrix[0][i]=='1'){
                v_size[0][i]=1;
                max_size=1;
            }
        }
        for(int i=0;i<rows;i++){
            if(matrix[i][0]=='1'){
                v_size[i][0]=1;
                max_size=1;
            }
        }
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][j]=='0')
                    continue;
                else{
                    v_size[i][j]=min(v_size[i][j-1],min(v_size[i-1][j],v_size[i-1][j-1]))+1;
                    if(v_size[i][j]>max_size)
                        max_size=v_size[i][j];
                }
            }
        }
        return max_size*max_size;
    }
};