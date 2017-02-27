/**
Given inorder and postorder traversal of a tree, construct the binary tree.
Note:
You may assume that duplicates do not exist in the tree.
Subscribe to see which companies asked this question.
思路：
          1       
         / \   
        2   3   
       / \ / \   
      4  5 6  7

对于上图的树来说，
        index: 0 1 2 3 4 5 6
     中序遍历为: 4 2 5 1 6 3 7
     后续遍历为: 4 5 2 6 7 3 1
可以发现的规律是：
1. 中序遍历中根节点是左子树右子树的分割点。
2. 后续遍历的最后一个节点为根节点。

同样根据中序遍历找到根节点的位置，然后顺势计算出左子树串的长度。在后序遍历中分割出左子树串和右子树串，递归的建立左子树和右子树。
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int size = inorder.size();
        if(size <= 0){
            return nullptr;
        }//if
        return InPostBuildTree(inorder,postorder,0,size-1,size);
    }
private:
    TreeNode* InPostBuildTree(vector<int> &inorder,vector<int> &postorder,int inIndex,int postIndex,int size){
        if(size <= 0){
            return nullptr;
        }//if
        // 根节点
        TreeNode* root = new TreeNode(postorder[postIndex]);
        // 寻找postorder[postIndex]在中序序列中的下标
        int index = 0;
        for(int i = 0;i < size;++i){
            if(postorder[postIndex] == inorder[inIndex+i]){
                index = inIndex+i;
                break;
            }//if
        }//for
        int leftSize = index - inIndex;
        int rightSize = size - leftSize - 1;
        root->left = InPostBuildTree(inorder,postorder,inIndex,postIndex-1-rightSize,leftSize);
        root->right = InPostBuildTree(inorder,postorder,index+1,postIndex-1,rightSize);
        return root;
    }
};
