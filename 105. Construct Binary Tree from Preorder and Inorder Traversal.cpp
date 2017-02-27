/**
Given preorder and inorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
Subscribe to see which companies asked this question.
分析：这道题实际上是考察如何从前序遍历和中序遍历中构造树。思想是：对于前序遍历而言，第一个元素一定为根节点。而对于中序遍历，根节点左边的都为左侧节点，根节点右边的都为右侧节点（找到了左侧长度和右侧长度）。然后前序遍历中，顺序依次为root，左侧节点和右侧节点。 
此时，已经找打了一个树的root，左子树部分的前序遍历、左子树的中序遍历，右子树的前序遍历和右子树的中序遍历。利用递归，构造成一棵生成树。
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return nullptr;
        if(preorder.size()==1)
            return new TreeNode(preorder[0]);
        TreeNode* root=nullptr;
        int size=preorder.size();
        root=helper(preorder,inorder,0,0,size);
        return root;
    }
    //in_index: start of inorder.  pre_index: root location.
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int in_index, int pre_index, int size){
        if (size<=0)
            return nullptr;
        if(size==1)
            return new TreeNode(preorder[pre_index]);
        TreeNode* root=new TreeNode(preorder[pre_index]);
        int loc_of_root=0;
        //find the location of root to sperate it.
        while((inorder[in_index+loc_of_root]!=preorder[pre_index])&&(loc_of_root<in_index+size))  
            loc_of_root++; 
        int size_of_right=size-loc_of_root-1;
        root->left=helper(preorder,inorder,in_index,pre_index+1,loc_of_root);
        root->right=helper(preorder,inorder,in_index+loc_of_root+1,pre_index+loc_of_root+1,size_of_right);
        return root;
    }
};
