/**
顺时针打印矩阵 
题目描述
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
思路：
通常当我们遇到一个复杂的问题的时候，我们可以用图形帮助我们思考。由于我们是以从外圈到内圈的顺序依次打印，我们在矩阵中标注一圈作为我们分析的目标。在下图中，我们设矩阵的宽度为columns，而其高度为rows。我们我们选取左上角坐标为(startX, startY)，右下角坐标为(endX, endY)的一个圈来分析。
由于endX和endY可以根据startX、startY以及columns、rows来求得，因此此时我们只需要引入startX和startY两个变量。我们可以想象有一个循环，在每一次循环里我们从(startX, startY)出发按照顺时针打印数字。
接着我们分析这个循环结束的条件。对一个5×5的矩阵而言，最后一圈只有一个数字，对应的坐标为(2, 2)。我们发现5 > 2 * 2。对一个6×6的矩阵而言，最后一圈有四个数字，对应的坐标仍然为(2, 2)。我们发现6 > 2 * 2依然成立。于是我们可以得出，让循环继续的条件是columns > startX * 2 && rows > startY * 2。
接下来我们分析如何在PrintMatrixInCircle中按照顺时针的顺序打印一圈的数字。如同在图中标注的那样，我们可以分四步来打印：第一步是从左到右打印一行，第二步是从上到下打印一列，第三步从右到左打印一行，最后一步是从下到上打印一列。也就是我们把打印一圈数字这个问题，分解成四个子问题。我们可以为每个子问题定义一个函数。
接下来我们需要考虑特殊情况。并不是所有数字圈都需要四步来打印。比如当一圈退化成一行的时候，也就是startY等于endY的时候，我们只需要第一步就把所有的数字都打印完了，其余的步骤都是多余的。因此我们需要考虑第二、三、四步打印的条件。根据前面我们分析，不难发现打印第二步的条件是startY < endY。对于第三步而言，如果startX等于endX，也就是这一圈中只有一列数字，那么所有的数字都在第二步打印完了；如果startY等于endY，也就是这一圈中只有一行数字，那么所有的数字都在第一步打印完了。因此需要打印第三步的条件是startX < endX && startX < endY。第四步最复杂，首先startX要小于endX，不然所有的数字都在一列，在第二步中就都打印完了。另外，这个圈中至少要有三行数字。如果只有一行数字，所有数字在第一步中打印完了；如果只有两行数字，所有数字在第一步和第三步也都打印完了。因此打印第四步需要的条件是startY < endY – 1。
**/
class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
	if(matrix.empty())
            return {};
        int rows=matrix.size();
        if(matrix[0].empty())
            return {};
        int cols=matrix[0].size();
        int start=0;
        vector<int> res;
        while(cols>start*2 && rows>start*2){
            PrintInCircle(matrix, res,rows,cols,start);
            ++start;
        }
        return res;
    }
    void PrintInCircle(vector<vector<int> > &matrix,vector<int> &res, int rows, int cols, int start){
        int x=cols-1-start;
        int y=rows-1-start;
        for(int i=start; i<=x;i++){
            res.push_back(matrix[start][i]);
        }       
        if(start<y){
            for(int i=start+1;i<=y;i++)
                res.push_back(matrix[i][x]);
        }
        if(start<x && start<y){
            for(int i=x-1;i>=start;i--)
                res.push_back(matrix[y][i]);
        }
        if(start<x && (start+1)<y){
            for(int i=y-1;i>=start+1;i--)
                res.push_back(matrix[i][start]);
        }
    }
};