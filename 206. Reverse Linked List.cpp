// 206. Reverse Linked List
// Reverse a singly linked list.
// 思路：两个指针 ，不断让后面的指向前面的。
// 注意：要把头节点的next置为nullptr。
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
    ListNode* reverseList(ListNode* head) {
        if(!head)
            return head;
        auto slow=head;
        auto quick=head->next;
        head->next=nullptr;
        while(quick!=nullptr){
            auto temp=quick->next;
            quick->next=slow;
            slow=quick;
            quick=temp;
        }
        return slow;
    }
};