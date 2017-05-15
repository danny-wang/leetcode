/**
129. Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.

思路： 递归，直到到达叶节点返回，中间保存路径上的值
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
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
            return 0;
        vector<int> mid;
        vector<int> temp;
        helper(root,temp,mid);
        int result=0;
        for(auto i : mid){
            result+=i;
        }
        return result;
    }
    void helper(TreeNode* root, vector<int> temp, vector<int>& mid){
        temp.push_back(root->val);
        if((root->left==nullptr) && (root->right==nullptr)){
            int a=0;
            stringstream ss;
            for(int i=0;i<temp.size();i++)
                ss<<temp[i];
            ss>>a;
            mid.push_back(a);
            return;
        }
        
        if(root->left)
            helper(root->left,temp ,mid);
        if(root->right)
            helper(root->right,temp,mid);
    }
};