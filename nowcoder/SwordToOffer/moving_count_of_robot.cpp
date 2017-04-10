/**
机器人的运动范围 
题目描述
地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。
 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？

思路：我们采用回溯法。机器人从[0,0]格子开始移动，当它移动到下一个格子的时候，我们通过格子的数位来判断该机器人是否有权利进入，如果可以，格子数+1，我们再判断[i-1,j],[i,j-1][i+1,j],[i,j+1]这相邻的四个格子能否进入。
**/
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        if(rows<1 ||cols<1 )
            return 0;
        bool* sig=new bool[rows*cols];
        for(int i=0;i<rows*cols;i++)
            sig[i]=false;
        int count=0;
        Helper(threshold,rows,cols,0,0,sig,count);
        delete[] sig;
        return count;
        
        
    }
    void Helper(int threshold, int rows, int cols, int row, int col, bool* sig, int &count){
        if(row>=0 &&row<rows && col>=0&& col<cols && sig[row*cols+col]==false){
            if(Check(row,col,threshold)){
                count++;
                sig[row*cols+col]=true;
                Helper(threshold,rows,cols,row+1,col,sig,count);
                Helper(threshold,rows,cols,row-1,col,sig,count);
                Helper(threshold,rows,cols,row,col+1,sig,count);
                Helper(threshold,rows,cols,row,col-1,sig,count);
            }
            else
                return;
        }
        return;
    }
    bool Check(int row, int col, int threshold){
        int a=GetDigitSum(row);
        int b=GetDigitSum(col);
        if(a+b>threshold)
            return false;
        else
            return true;
    }
    
    int GetDigitSum(int val){
        int res=0;
        while(val){
            int temp=val%10;
            res+=temp;
            val/=10;
        }
        return res;
    }
};