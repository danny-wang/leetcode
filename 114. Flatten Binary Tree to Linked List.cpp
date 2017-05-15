/**
114. Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.
For example,
Given
         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

click to show hints.
Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
思路1：从图中可以看出，展开后是原二叉树先根遍历的顺序
首先对二叉树进行先根遍历，将顺序存储到vector中，然后按这个顺序重构即可。
空间复杂度为O(n)，时间复杂度为O(n)
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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> stack;
        TreeNode* temp=root;
        vector<TreeNode*> vec;
        while(temp || !stack.empty()){
            if(temp){
                stack.push(temp);
                vec.push_back(temp);
                temp=temp->left;
            }
            else{
                temp=stack.top();
                stack.pop();
                temp=temp->right;
            }
        }
        TreeNode* ptr=root;
        for(int i=1;i<vec.size();i++){
            ptr->left=nullptr;
            ptr->right=vec[i];
            ptr=ptr->right;
        }
        
    }
};
//思路2：
//　从根结点（root）找左子树（l）的最右子结点（x），将root的右子树（r）接到x的右子树上（x的右子树为空），root的左子树整体调整为右子树，root的左子树赋空。 空间复杂度为O(1).时间复杂度为O(logn*logn)

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
    void flatten(TreeNode* root) {
        TreeNode* ptr=root;
        while(ptr){
            OneStep(ptr);
            ptr=ptr->right;
        }
    }
    void OneStep(TreeNode* root){
        if(!root)
            return;
        TreeNode* ptr=root;
        while(ptr){   //　从根结点（root）找左子树（l）的最右子结点（x）
            if(ptr->left)
                ptr=ptr->left;
            else
                break;
            while(ptr->right)
                ptr=ptr->right;
        }
        if(ptr==root)  //如果没有左子树
            return;
        ptr->right=root->right;
        root->right=root->left;
        root->left=nullptr;
            
    }
};