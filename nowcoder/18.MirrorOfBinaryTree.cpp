/**
二叉树的镜像 
题目描述
操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述:

二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5
思路：前序遍历这棵树的每个节点，有子结点，就交换
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
    void Mirror(TreeNode *pRoot) {
	SwapChild(pRoot);
        return;
    }
    
    void SwapChild(TreeNode* root){
        if(root==nullptr)
        	return;
        else{
            TreeNode* temp=root->left;
            root->left=root->right;
            SwapChild(root->left);
            root->right=temp;
            SwapChild(root->right);
        }
        return;
    }
};
