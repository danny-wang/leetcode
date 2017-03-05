/**
Given numRows, generate the first numRows of Pascal's triangle.
For example, given numRows = 5,
Return
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

思路：Pascal's triangle：每一层的第i个位置，等于上一层第i-1与第i个位置之和。
代码：
**/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows<=0)
            return {};
        vector<vector<int>> result;
        vector<int> temp={1};
        result.push_back(temp);
        if(numRows==1){
            return result;
        }
        for(int i=2;i<=numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=2;j<i;j++){
                temp.push_back((result[i-2])[j-2] + (result[i-2])[j-1]);
            }
            temp.push_back(1);
            result.push_back(temp);
        }
        return result;
    }
};