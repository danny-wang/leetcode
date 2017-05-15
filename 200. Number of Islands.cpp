/**
200. Number of Islands
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1
Example 2:
11000
11000
00100
00011
Answer: 3

思路：对每次出现'1'的区域进行计，同时深度或广度遍历，然后将他们的标记置为true.
**/
class Solution {
public:
	int numIslands(vector<vector<char>>& grid) {
		if (grid.empty() || grid[0].empty())
			return 0;
		int rows = grid.size();
		int cols = grid[0].size();
		bool** sig = new bool*[rows];
		for (int i = 0; i<rows; i++)
			sig[i] = new bool[cols];
		for (int i = 0; i<rows; i++){
			for (int j = 0; j<cols; j++){
				sig[i][j] = false;
			}
		}
		int count = 0;
		for (int i = 0; i<rows; i++){
			for (int j = 0; j<cols; j++){
				if (grid[i][j] == '1'&&sig[i][j] == false){
					cout << i << " " << j << endl;
					helper(grid, sig, i, j, rows, cols);
					count++;
				}
			}
		}
		return count;
	}
	void helper(vector<vector<char>>& grid, bool **sig, int i, int j, int rows, int cols){
		sig[i][j] = true;
		if (i - 1 >= 0){
			if (grid[i - 1][j] == '1'&&sig[i - 1][j] == false)
				helper(grid, sig, i - 1, j, rows, cols);

		}
		if (j - 1 >= 0){
			if (grid[i][j - 1] == '1'&&sig[i][j - 1] == false)
				helper(grid, sig, i, j - 1, rows, cols);
		}
		if (i + 1<rows){
			if (grid[i + 1][j] == '1'&&sig[i + 1][j] == false)
				helper(grid, sig, i + 1, j, rows, cols);
		}
		if (j + 1<cols){
			if (grid[i][j + 1] == '1'&&sig[i][j + 1] == false)
				helper(grid, sig, i, j + 1, rows, cols);
		}


	}
};