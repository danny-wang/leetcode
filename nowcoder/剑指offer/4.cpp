/**
重建二叉树
题目描述
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。 
**/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
	if(pre.size()==0)
            return nullptr;
        TreeNode* root;
        root=helper(pre,vin,0,0,pre.size());
        return root;       
    }
    TreeNode* helper(vector<int> pre, vector<int> vin, int pre_head, int vin_head, int size){
        if(size==0)
            return nullptr;
        if(size==1)
            return new TreeNode( pre[pre_head]);
        int index=0;
        for(int i=vin_head;i<vin_head+size;i++){
            if(vin[i]==pre[pre_head]){
            	index=i;
                break;
            }
        }
        int left_sub_tree_size=index-vin_head;
        int right_sub_tree_size=size-left_sub_tree_size-1;
        TreeNode* root=new TreeNode( pre[pre_head]);
        root->left=helper(pre,vin,pre_head+1,vin_head,left_sub_tree_size);
        root->right=helper(pre,vin,pre_head+left_sub_tree_size+1, index+1,right_sub_tree_size );
        return root;
        
    }
};
