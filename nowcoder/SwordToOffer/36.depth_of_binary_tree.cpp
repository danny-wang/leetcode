/**
二叉树的深度

题目描述
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
最长路径的长度为树的深度。
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
    int TreeDepth(TreeNode* pRoot)
    {
    	int  max_length=0;
        if(pRoot==nullptr)
            return 0;
        helper(pRoot,1, max_length);
        return max_length;
    }
    void helper(TreeNode* root, int cur_length, int &max_length){
        if(cur_length>max_length)
            max_length=cur_length;
        if(root->left)
            helper(root->left, cur_length+1, max_length);
        if(root->right)
            helper(root->right,cur_length+1, max_length);
        return;
    }
};