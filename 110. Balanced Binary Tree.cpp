/**
110. Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

分析：树上的任意结点的左右子树高度差不超过1，则为平衡二叉树。
         搜索递归，记录i结点的左子树高度h1和右子树高度h2，则i结点的高度为max(h1,h2)+1，|h1-h2|>1则不平衡。一旦发现有一个节点不平衡，就可以直接返回了。
**/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balanced=true;  //标识是否是平衡树
        GetHigh(root, balanced);
        return balanced;
    }
    int GetHigh(TreeNode* node, bool &balanced){
        if(!balanced)
            return -1;
        if(node==nullptr)
            return 0;
        int left=GetHigh(node->left, balanced);
        int right=GetHigh(node->right,balanced);
        if((left-right)>1 || (left-right)<-1)   //在当前节点不平衡
            balanced=false;
        return max(left,right)+1;  
    }


};