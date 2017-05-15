/**
328. Odd Even Linked List

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.
Note:
The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...

思路：把奇数连接起来，偶数连接起来，最后连接奇偶。
注意：奇数链表的下一个就是偶数链表尾节点的next，反之亦然。
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || head->next==nullptr)
            return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* odd_temp=odd;
        ListNode* even_temp=even;
        bool sig=true; //true:下一次处理奇数位置的节点。 false：下一次处理偶数位置的节点
        while(even_temp->next !=nullptr && odd_temp->next!=nullptr ){
            if(sig){
                odd_temp->next=even_temp->next;
                odd_temp=odd_temp->next;
                sig=false;
            }
            else{
                even_temp->next=odd_temp->next;
                even_temp=even_temp->next;
                sig=true;
            }
        }
        odd_temp->next=even;
        even_temp->next=nullptr;
        return odd;
        
    }
};