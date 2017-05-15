/**
257. Binary Tree Paths
Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:
   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:
["1->2->5", "1->3"]
思路：递归  指导到达叶节点
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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return {};
        vector<string> result;
        stringstream ss;
        ss<<root->val;
        string temp=ss.str();
        if(!root->left&& !root->right){
            result.push_back(temp);
            return result;
        }
        if(root->left)
            helper(result, root->left,temp);
        if(root->right)
            helper(result,root->right,temp);
        return result;
    }
    void helper(vector<string>& result, TreeNode* ptr, string cur){
        stringstream ss;
        ss<<ptr->val;
        string temp=ss.str();
        if(!ptr->left && !ptr->right){
            cur=cur+"->"+temp;
            result.push_back(cur);
        }
        else{
            if(ptr->left)
                helper(result,ptr->left,cur+"->"+temp);
            if(ptr->right)
                helper(result,ptr->right,cur+"->"+temp);
        }
    }
};