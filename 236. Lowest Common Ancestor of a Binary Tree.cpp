/**
236. Lowest Common Ancestor of a Binary Tree
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”
        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4

For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

思路： 如果是普通二叉树, 而不是BST.  则应该遍历节点, 先找到p,q. 同时记录下从root到该节点的路径.   之后比较路径,最后一个相同的节点便是LCA.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q)
            return root;
        stack<TreeNode*> sta_a,sta_b;
        inorder_search(root,p,sta_a);
        inorder_search(root,q,sta_b);
        stack<TreeNode*> reverse_a, reverse_b;
        while(!sta_a.empty()){
            reverse_a.push(sta_a.top());
            sta_a.pop();
        }
        while(!sta_b.empty()){
            reverse_b.push(sta_b.top());
            sta_b.pop();
        }
        TreeNode* result=0;
        while(!reverse_a.empty()&&!reverse_b.empty()){
            if(reverse_a.top()==reverse_b.top()){
                result=reverse_a.top();
                reverse_a.pop();
                reverse_b.pop();
            }
            else
                break;
        }
        return result;
    }
    bool inorder_search(TreeNode *root, TreeNode* p, stack<TreeNode*>& s){  //路径
        if(root==nullptr)
            return false;
        if(root==p){
            s.push(root);
            return true;
        }
        s.push(root);
        if(inorder_search(root->left,p,s))
            return true;
        if(inorder_search(root->right,p,s))
            return true;
        s.pop();
        return false;
        
    }
};