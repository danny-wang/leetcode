/**
59. Spiral Matrix II 

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example,
Given n = 3,
You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
思路：与54题相同
**/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n<1)
            return {};
        int start=0;
        int cur_val=1;
        vector<vector<int>> res(n,vector<int>(n));
        while(n>start*2 && n>start*2){
            PrintInCircle(res,n, start, cur_val);
            ++start;
        }
        return res;
    }
    void PrintInCircle(vector<vector<int> > &matrix, int n,int start, int& cur_val){
        int x=n-1-start;
        int y=n-1-start;
        for(int i=start; i<=x;i++){
           matrix[start][i]=cur_val++;
        }       
        if(start<y){
            for(int i=start+1;i<=y;i++)
                matrix[i][x]=cur_val++;
        }
        if(start<x && start<y){
            for(int i=x-1;i>=start;i--)
                matrix[y][i]=cur_val++;
        }
        if(start<x && (start+1)<y){
            for(int i=y-1;i>=start+1;i--)
                matrix[i][start]=cur_val++;
        }
    }
};
