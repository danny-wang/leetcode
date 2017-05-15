/**
109. Convert Sorted List to Binary Search Tree
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
解题思路：
参考题目：108. Convert Sorted Array to Binary Search Tree
如果链表是空的，那么构造出来的BST也是空的。
如果链表只有一个节点，那么构造出来的BST也只有一个节点。
如果链表有两个或更多节点，那就找出中间的节点，用它构造根节点。它左边的链表构造左子树，右边的链表构造右子树。
寻找中间节点的方法：快、慢指针。
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        if(head->next==nullptr)
            return (new TreeNode(head->val));
        //slow->next是中间节点 slow->next->next为右半边链表，slow为左半边链表的尾节点。
        ListNode* slow=head;
        ListNode* fast=head->next->next;
        while(fast && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        TreeNode* root=new TreeNode(slow->next->val);
        root->right=sortedListToBST(slow->next->next);
        slow->next=nullptr;
        root->left=sortedListToBST(head);
        return root;
        
    }
};