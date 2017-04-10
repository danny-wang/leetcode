/**
二叉树的下一个结点 

题目描述
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
思路：
分情况讨论：
1.如果当前节点有右子树，则它的下一个节点就是它右子树的中根遍历的第一个输出节点（不断的找左孩子）
2.如果当前节点没有右子树，并且它是它父节点的左孩子，则他的下一个节点就是他的父节点
3.如果当前节点没有右子树，并且它是它父节点的右孩子，则他的下一个节点就是不断的往上找，直到找到一个节点是他父节点的左孩子，则它的下一个节点就是这个节点的父节点
**/
/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==nullptr)
            return nullptr;
        if(pNode->right!=nullptr){
            TreeLinkNode* ptr=pNode->right;
            while(ptr->left)
                ptr=ptr->left;
            return ptr;
        }
        else{//pNode doesn't have right node
            if(pNode->next==nullptr) //pNode doesn't have parent
                return nullptr;
            else{
                if(pNode->next->left==pNode)
                    return pNode->next;
                else{  //pNode is his parent's right node
                    TreeLinkNode* ptr=pNode->next;
                    while(ptr->next!=nullptr){
                        if(ptr->next->left==ptr)
                            return ptr->next;
                        else
                            ptr=ptr->next;
                    }
                    return nullptr;
                }
                 
            }
        }
    }
};