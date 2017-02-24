/**
Given a binary tree, return the postorder traversal of its nodes' values.
For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3

return [3,2,1].
非递归方式的思想就是需要记录访问的结点是否是第一次访问的。因为当前结点需要在左右子数访问之后才能输出。
所以需要标志来记录当前结点是否右子树已经访问过。当访问过的时候才输出。
详细信息参考：https://github.com/danny-wang/c-_primer_code/blob/master/mycode/DataStructs/BinaryTree.h
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
    typedef struct{
        TreeNode* node;
        char tag;
    }tree_node_post, *ptr_tree_node; 
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* ptr=root;
        ptr_tree_node post_ptr;
        stack<ptr_tree_node> stack_of_tree;
        while(ptr || !stack_of_tree.empty()){
            while(ptr){
                post_ptr = new tree_node_post;
                post_ptr->node=ptr;
                post_ptr->tag='L';
                stack_of_tree.push(post_ptr);
                ptr=ptr->left;
            }
            while(!stack_of_tree.empty() && (stack_of_tree.top())->tag=='R'){
                ptr_tree_node ptr_cur=stack_of_tree.top();
                result.push_back(ptr_cur->node->val);
                stack_of_tree.pop();
            }
            if(!stack_of_tree.empty()){
                ptr_tree_node ptr_cur=stack_of_tree.top();
                ptr_cur->tag='R';
                ptr=ptr_cur->node->right;
            }
        }
        return result;
    }
};
