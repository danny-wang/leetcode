/**
404. Sum of Left Leaves
Find the sum of all left leaves in a given binary tree.
Example:
    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

思路：
从思路来说也没有什么特别的地方，就是去做判断，细心一点不要有漏洞就好。
大体上分为判断有没有左节点和有没有右节点。如果有左节点，看左节点有没有子节点，没有（即左叶子节点）则直接用起值去加，有则继续对左节点递归。
如果有右节点，且右节点有子节点，则对右节点递归，否则不管是没有右节点还是右节点没有子节点（即右叶子节点）都直接看做加0。
需要注意的是如果本身节点自己是null，要返回0。另外如果只有根节点自己，也要返回0，因为题目说的是左叶子节点，根节点是不算的。
最后要注意的就是在判断所有节点的子节点或者值之前，要对该节点本身是否为null做出判断，否则会有错误的。

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
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        if(!root)
            return res;
        sum(root,res);
        return res;
    }
    void sum(TreeNode* root, int &res){
        if(root->left){
            if(root->left->left==nullptr && root->left->right==nullptr)
                res+=root->left->val;
            else
                sum(root->left,res);
        }
        if(root->right){
            sum(root->right, res);
        }
    }