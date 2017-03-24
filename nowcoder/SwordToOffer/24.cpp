/**
二叉树中和为某一值的路径 
题目描述
输入一颗二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。 
**/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(!root)
            return {};
	vector<int> cur;
        vector<vector<int>> result;
        helper(result,cur,0,expectNumber,root);
        return result;
    }
    void helper(vector<vector<int>>& result,vector<int>& cur, int cur_sum, int expect_sum, TreeNode* root ){
        cur_sum+=root->val;
        cur.push_back(root->val);
        if(root->left==nullptr && root->right==nullptr){
            if(cur_sum==expect_sum){
                result.push_back(cur);
            }
            cur.pop_back();
            return;
        }
        else{
            if(root->left){
                helper(result, cur, cur_sum, expect_sum, root->left);
            }
            if(root->right){
                helper(result, cur, cur_sum, expect_sum, root->right);
            }
        }
        cur.pop_back();
        return;
            
    }
};
