/**
101. Symmetric Tree
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
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
    bool symmetric(TreeNode* left, TreeNode* right){
        if(left==NULL && right==NULL)
            return true;
        if(left && right && left->val==right->val)
            return (symmetric(left->left, right->right) &&  symmetric(left->right,right->left));
        else
            return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root== NULL)
            return true;
        else
            return symmetric(root->left,root->right);
    }
    
};
/**
思路二：通常我们有三种不同的二叉树遍历算法。在这三种遍历算法之中，都是先遍历左子节点，再遍历右子节点。
针对前序遍历定义对称遍历算法，也就是先遍历根节点，在遍历它的右子节点，然后遍历左子节点。
如果二叉树是对称的，那么两种遍历出来的序列一定是一致的。
注意：需要把遇到的nullptr指针也考虑进去。
**/
/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
      if(pRoot==nullptr)
            return true;
        vector<TreeNode*> pre_list;
        vector<TreeNode*> symmetric_pre_list;
        stack<TreeNode*> node_stack;
        TreeNode* ptr=pRoot;
        while(ptr || (!node_stack.empty())){
            if(ptr){
                pre_list.push_back(ptr);
                node_stack.push(ptr);
                ptr=ptr->left;
            }
            else{
                pre_list.push_back(ptr);
                TreeNode* top=node_stack.top();
                node_stack.pop();
                ptr=top->right;
            }
        }
        ptr=pRoot;
        while(!node_stack.empty()){
            node_stack.pop();
        }
        while(ptr || (!node_stack.empty())){
            if(ptr){
                symmetric_pre_list.push_back(ptr);
                node_stack.push(ptr);
                ptr=ptr->right;
            }
            else{
                symmetric_pre_list.push_back(ptr);
                TreeNode* top=node_stack.top();
                node_stack.pop();
                ptr=top->left;
            }
        }
        if(pre_list.size()==symmetric_pre_list.size()){
            for(int i=0;i<symmetric_pre_list.size();i++){
                if(pre_list[i]==nullptr && symmetric_pre_list[i]==nullptr )
                    continue;
                else if(pre_list[i]==nullptr || symmetric_pre_list[i]==nullptr )
                    return false;
                else if(pre_list[i]->val == symmetric_pre_list[i]->val)
                    continue;
                else
                    return false;
            }
            return true;
        }
        else
            return false;
        
    }
};