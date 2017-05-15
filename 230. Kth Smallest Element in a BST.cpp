/**
230. Kth Smallest Element in a BST
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
Note: 
You may assume k is always valid, 1 ? k ? BST's total elements.
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

思路：BST的中根遍历是升序排列的，用循环的方式去对树进行中根遍历，到第K个元素的时候返回val即可 时间复杂度O（k）,空间复杂度0（h）.
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
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return INT_MIN;
        TreeNode* ptr=root;
        stack<TreeNode*> sta;
        int count=0;
        while(ptr || !sta.empty()){
            if(ptr){
                sta.push(ptr);
                ptr=ptr->left;
            }
            else{
                count++;
                ptr=sta.top();
                sta.pop();
                if(count==k){
                    return ptr->val;
                }
                ptr=ptr->right;
            }
        }
        return INT_MIN;
    }
};