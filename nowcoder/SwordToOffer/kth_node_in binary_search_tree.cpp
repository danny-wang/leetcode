/**
二叉搜索树的第k个结点 

题目描述
给定一颗二叉搜索树，请找出其中的第k大的结点。例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
思路：
二叉搜索树的中根遍历的值是递增排序的，要获得第K大的节点，只需要中根遍历之后求第K的即可。
使用一个栈作为中根遍历的辅助容器，那么弹出的顺序是递增排序的，只需要获得第K个弹出的节点即可。
代码：
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
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(!pRoot ||k<1)
            return nullptr;
        stack<TreeNode*> node_stack;
        TreeNode* ptr=pRoot;
        int i=0;
        while(ptr || !node_stack.empty()){
            if(ptr){
                node_stack.push(ptr);
                ptr=ptr->left;
            }
            else{
                ptr=node_stack.top();
                node_stack.pop();
                i++;
                if(i==k){
                    return ptr;//find result
                }
                ptr=ptr->right;
            }
        }
        return nullptr; //k is bigger than node number in binary tree
    }

    
};