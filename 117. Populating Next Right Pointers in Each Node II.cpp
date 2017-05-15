/**
117. Populating Next Right Pointers in Each Node II
Follow up for problem "Populating Next Right Pointers in Each Node".
What if the given tree could be any binary tree? Would your previous solution still work?
Note:
  ● You may only use constant extra space.
For example,
Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

分析
本题的解法完全可以用于Populating Next Right Pointers in Each Node。
本题的一个难点在于要求使用常数空间，这样的话普通的深度优先遍历由于需要递归压栈而无法使用，普通的广度优先搜索需要使用队列也无法使用，因此选择使用两层迭代，使用current指向当前结点的方法进行广度优先遍历。
同之前的简化版本不同，本题的区别在于二叉树并不完整，之前算法中可以将当前结点的右子结点与下一结点的左子结点相连的方法失效。因此这里选用广度优先遍历，引入“层”的概念，不断去寻找当前层的下一个节点。

**/
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
        TreeLinkNode* first=root; //first node in this level
        root->next=nullptr;
        bool find_first=false;
        while(first){
            TreeLinkNode* temp=first; //every node in this level
            first=nullptr;
            find_first=false;
            while(temp){
                if(temp->left){
                    if(find_first==false){
                        find_first=true;
                        first=temp->left;
                    }
                    if(temp->right){
                        temp->left->next=temp->right;
                    }
                    else{
                        TreeLinkNode* ptr=temp->next;
                        while(ptr){
                            if(ptr->left){
                                temp->left->next=ptr->left;
                                break;
                            }
                            else if(ptr->right){
                                temp->left->next=ptr->right;
                                break;
                            }
                            ptr=ptr->next;
                        }
                        if(ptr==nullptr){
                            temp->left->next=nullptr;
                            break;
                        }
                    }
                }
                if(temp->right){
                    if(find_first==false){
                        find_first=true;
                        first=temp->right;
                    }
                    TreeLinkNode* ptr=temp->next;
                    while(ptr){
                        if(ptr->left){
                            temp->right->next=ptr->left;
                            break;
                        }
                        else if(ptr->right){
                            temp->right->next=ptr->right;
                            break;
                        }
                        ptr=ptr->next;
                    }
                    if(ptr==nullptr){
                        temp->right->next=nullptr;
                        break;
                    }
                   
                }
                temp=temp->next;
            }
        }
    }
};