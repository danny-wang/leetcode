/**
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
  ● The left subtree of a node contains only nodes with keys less than the node's key.
  ● The right subtree of a node contains only nodes with keys greater than the node's key.
  ● Both the left and right subtrees must also be binary search trees.
Example 1:
    2
   / \
  1   3

Binary tree [2,1,3], return true.
Example 2:
    1
   / \
  2   3

Binary tree [1,2,3], return false.

二叉搜索树的中根遍历一定是升序的，先求中根遍历，判断是否升序，时间复发度O(n)
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
    bool isValidBST(TreeNode* root) {
        if(root==nullptr)
            return true;
        stack<TreeNode*> node_stack;
        TreeNode* ptr=root;
        vector<int> medium_array;
        while(ptr || !node_stack.empty()){
            if(ptr){
                node_stack.push(ptr);
                ptr=ptr->left;
            }
            else{
                ptr=node_stack.top();
                medium_array.push_back(ptr->val);
                node_stack.pop();
                ptr=ptr->right;
            }
        }
        for(int i=1;i<medium_array.size();i++){
            if(medium_array[i]>medium_array[i-1])
                continue;
            else
                return false;
        }
        return true;
         
        
    }
};