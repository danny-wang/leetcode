/**
题目描述
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。 
思路：从右向左，逐渐缩减范围，直到找到或者行数或者列数超出了范围
**/
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty())
            return false;
        int row_length=array[0].size()-1;
        int col_length=array.size()-1;
        int col_number=row_length;
        int row_number=0;
       	while(col_number>=0 && row_number<=col_length){
            if(array[row_number][col_number]==target)
                return true;
           	else if(array[row_number][col_number]>target){
                col_number--;
            }
            else{
                row_number++;
            }
        }
        return false;
            
        
    }
};
