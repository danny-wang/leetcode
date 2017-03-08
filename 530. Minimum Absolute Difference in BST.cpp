/**
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
Example:
Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

Note: There are at least two nodes in this BST.
思路：要求二叉搜索树中两个节点值差的最小值，首先对二叉搜索树进行中根遍历，因为二叉搜索树左子树小于根节点，根节点小于右子树的特性，所以中根遍历的输出一定是升序排列的，依次比较，求相邻两个元素的差，最小值即是解。
代码：
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
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr)
            return 0;
        stack<TreeNode*> node_stack;
        TreeNode* temp=root;
        vector<int> result;
        while(node_stack.size()!=0 || temp!=nullptr){
            while(temp!=nullptr){
                node_stack.push(temp);
                temp=temp->left;
            }
            if(node_stack.size()!=0){
                TreeNode* p=node_stack.top();
                result.push_back(p->val);
                node_stack.pop();
                temp=p->right;
            }
        }
        int min_diff=INT_MAX;
        for(int i=1;i<result.size();i++){
            if(result[i]-result[i-1]<min_diff)
                min_diff=result[i]-result[i-1];
        }
        return min_diff;
    }
};