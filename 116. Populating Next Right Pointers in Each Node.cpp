/**
116. Populating Next Right Pointers in Each Node
Given a binary tree
    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
  ● You may only use constant extra space.
  ● You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7

After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL

思路：将每个节点的父节点的指针作为参数传给它，它如果是父节点的左孩子，那它的next就是父节点的右孩子，如果它是父节点的右孩子，那父节点的next的左孩子就是它的next.但是这里用到了递归，空间复杂度为O（logn）,不满足题目要求

**/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
enum class NodeType{
    LEFT,
    RIGHT,
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        root->next=nullptr;
        helper(root->left, root, NodeType::LEFT);
        helper(root->right, root, NodeType::RIGHT);
    }
    void helper(TreeLinkNode *cur,TreeLinkNode *root, NodeType type){
        if(!cur)
            return;
        if(type==NodeType::LEFT){
            cur->next=root->right;
        }
        else{//type==NodeType::RIGHT
            if(root->next==nullptr)
                cur->next=nullptr;
            else
                cur->next=root->next->left;
        }
        helper(cur->left,cur,NodeType::LEFT);
        helper(cur->right,cur,NodeType::RIGHT);
        return;
    }
};
//思路2：任何递归都可以写成循环的形式，因为不用再栈上开辟空间，这样空间复杂度就是O（1）了
//大体思路和之前一样，这次一层一层处理，首先处理第一层，每个节点的左节点的next就是它的右节点，他的右节点的next就是它自己next的左节点（如果next节点存在的 话）.

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        root->next=nullptr;
        TreeLinkNode* first=root;  //每一层的首节点
        while(first){
            TreeLinkNode* temp=first;
            if(!temp->left)
                return;
            while(temp){ //分别处理这一层的每一个节点
                temp->left->next=temp->right;
                if(temp->next)
                    temp->right->next=temp->next->left;
                else //父节点的next为nullptr
                    temp->right=nullptr;
                temp=temp->next;
            }
            first=first->left;
        }
        return;
    }
};