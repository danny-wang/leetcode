// 108. Convert Sorted Array to Binary Search Tree
// Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
// Subscribe to see which companies asked this question.
// 解题思路：
// 如果数组是空的，返回空指针。
// 否则，取出中值，用它构造根节点。然后用数组中左边的元素构造左子树，右边的元素构造右子树。子树的构造是一个递归的过程。

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return nullptr;
        int l=0;
        int r=nums.size()-1;
        return helper(nums,l,r);
    }
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left>right)
            return nullptr;
        int medium=(left+right)>>1;
        TreeNode* root=new TreeNode(nums[medium]);
        root->left=helper(nums,left,medium-1);
        root->right=helper(nums,medium+1,right);
        return root;
    }
};