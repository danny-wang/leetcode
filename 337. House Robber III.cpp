/**
337. House Robber III 

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
Determine the maximum amount of money the thief can rob tonight without alerting the police.
Example 1:
     3
    / \
   2   3
    \   \ 
     3   1

Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1

Maximum amount of money the thief can rob = 4 + 5 = 9.

题意：不能连续抢直接相连的两个节点。即例2中，抢了3就不能抢4，5。问最多能抢好多。
给一个二叉树，求它不直接相连的节点的val和最大为多少。
如果抢了当前节点，那么它的左右孩子就肯定不能抢了。
如果没有抢当前节点，左右孩子抢不抢取决于左右孩子的孩子的val大小。
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
    int rob(TreeNode* root) {
        pair<int,int> result=dfs(root);
        return max(result.first, result.second);
    }
    //first means rob this house, second means not rob this house
    pair<int,int> dfs(TreeNode *node){
        if(!node)
            return make_pair(0,0);
        auto a=dfs(node->left);
        auto b=dfs(node->right);
        pair<int,int> temp;
        temp.first=node->val+a.second+b.second;
        temp.second=max(a.first,a.second)+max(b.first,b.second);
        return temp;
    }
};