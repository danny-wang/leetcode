/**
222. Count Complete Tree Nodes
Given a complete binary tree, count the number of nodes.
Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

完全二叉树，至少有一课子树是完美二叉树，另一课子树至少是完全二叉树。
因此可以递归的计算。
判断完美二叉树：
     最内侧的叶子结点和最外侧的叶子结点是否在同一层。

 如果从某节点一直向左的高度 = 一直向右的高度, 那么以该节点为root的子树一定是complete binary tree. 而 complete binary tree的节点数,可以用公式算出 2^h - 1. 如果高度不相等, 则递归调用 return countNode(left) + countNode(right) + 1.  复杂度为O(h^2)   
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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        auto l=root->left;
        auto r=root->right;
        int l_depth=1;
        int r_depth=1;
        while(l){
            l_depth++;
            l=l->left;
        }
        while(r){
            r_depth++;
            r=r->right;
        }
        if(l_depth==r_depth){
            return (pow(2,l_depth)-1);
        }
        else
            return 1+countNodes(root->left)+countNodes(root->right);
    }
};
