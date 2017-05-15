/**
203. Remove Linked List Elements
Remove all elements from a linked list of integers that have value val.
Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

思路：
要删除所有元素值为val的节点。
首先新建一个节点ptr 指向头节点;
如果当前节点的下一个节点元素为val，则将当前节点的next指向它next的next，并且删除它以前的next    
否则   将当前节点指向下一个节点
不断遍历以上两步直到到达尾部
**/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ptr=new ListNode(-1);
        ListNode* temp=ptr;
        ptr->next=head;
        while(temp->next){
            if(temp->next->val==val){
                ListNode* del=temp->next;
                temp->next=temp->next->next;
                delete del;
            }
            else
                temp=temp->next;
        }
        return ptr->next;
    }
};