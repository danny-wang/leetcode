/**
120. Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
思路一：用动态规划的方式，确定方程。设F(i,j)表示从最后一层到第i层第j个元素的最短路径。
那么就有：
F（i, j）=min(F(i+1,j)+A[i][j], F(i+1,j+1)+A[i][j] )   对于除了最后一层的其他层的节点 
F（i, j）=A[i][j],  对于最后一层的节点
但是这种递归的方式利用的空间比较多，在最后一个testcase的时候超时了
 Time Limit Exceeded
 **/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        if(triangle.size()==1 && triangle[0].size()==1)
            return triangle[0][0];
        return helper(0,0,triangle);
    }
    int helper(int row, int index, vector<vector<int>> &triangle){
        if(row==triangle.size()-1)
            return triangle[row][index];
        return min(helper(row+1, index,triangle)+triangle[row][index], helper(row+1,index+1,triangle)+triangle[row][index]);
    }
};
//思路二：将之前的递归方式换成循环的方式，就满足了题目的要求，从最后一层，一直到第一层
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==0)
            return 0;
        if(triangle.size()==1 && triangle[0].size()==1)
            return triangle[0][0];
        int row=triangle.size();
        vector<int> temp;
        for(int i=0;i<triangle[row-1].size();i++)
            temp.push_back(triangle[row-1][i]);
        row=row-1;
        while(row>0){
            vector<int> mid(temp);
            temp.clear();
            for(int i=0;i<row;i++){
                temp.push_back(min(mid[i]+triangle[row-1][i],mid[i+1]+triangle[row-1][i]));
            }
            row--;
        }
        return temp[0];
    }
};