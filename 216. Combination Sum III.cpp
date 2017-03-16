/**
216. Combination Sum III
Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Example 1:
Input: k = 3, n = 7
Output:
[[1,2,4]]


Example 2:
Input: k = 3, n = 9
Output:
[[1,2,6], [1,3,5], [2,3,4]]
思路：
ＤＦＳ：深度优先搜索
我觉得就是动态规划。与39 ， 40非常类似，只需要加两个判断条件，只有长度等于K的才加入。注意对长度大于K的进行剪枝 

第一步　ｐｏｓ和ｂａｓｅ都是０，
然后　分别放入从ｐｏｓ到ｃａｎｄｉｄａｔｅｓ中的最后一个元素，ｂａｓｅ加上相应的值，如果等于ｔａｒｇｅｔ就放入ｒｅｓｕｌｔ，如果大于，就放弃这条线，ｒｅｔｕｒｎ,否则继续执行放入一个新元素的操作，重复本步。　
这样就生成来所有可能的情况。
**/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidate={1,2,3,4,5,6,7,8,9};
        vector<int> temp;
        vector<vector<int>> result;
        helper(result, temp, candidate, 0, 0, k, n);
        return result;
        
    }
    void helper(vector<vector<int>>&result, vector<int>& temp,vector<int> candidate, int position, int cur_sum,int max_num, int obj){
        if(cur_sum==obj && temp.size()==max_num ){
            result.push_back(temp);
            return;
        }
        else if(cur_sum>obj || temp.size()>max_num)
            return;
        else{
            for(int i=position;i<9;i++){
                temp.push_back(candidate[i]);
                helper(result,temp,candidate, i+1, cur_sum+candidate[i], max_num,obj);
                temp.pop_back();
            }
        }
    }
};