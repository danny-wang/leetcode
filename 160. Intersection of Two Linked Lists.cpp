/**
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:
A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:
  ● If the two linked lists have no intersection at all, return null.
  ● The linked lists must retain their original structure after the function returns.
  ● You may assume there are no cycles anywhere in the entire linked structure.
  ● Your code should preferably run in O(n) time and use only O(1) memory.
思路：
找两个链表的交点，首先想到的是使用两个栈，然后将每个链表压入一个栈中，分别弹出每个元素，最后一个弹出的一模一样的元素就是他们的交点，但是这个思路的空间复杂度是 O(n)的
为了不使用额外的空间，首先计算每个链表的长度，然后长的那个减去他们长度的差值，剩下的部分则长度一致，一步一步往前走，遇到的第一个相同的元素则是他们的交点。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int headA_size=GetListLength(headA);
        int headB_size=GetListLength(headB);
        bool headA_longer=false;
        if(headA_size>=headB_size)
            headA_longer=true;
        int gap=abs(headA_size-headB_size);
        ListNode *rootA=headA;
        ListNode *rootB=headB;
        if(headA_longer){   //如果headA链表更长，headA先走gap步
            for(int i=0 ; i<gap; i++)
                rootA=rootA->next;
        }
        else{
            for(int i=0 ; i<gap; i++)
                rootB=rootB->next;
        }
        while(rootA){
            if(rootA->val==rootB->val && rootA->next==rootB->next)
                return rootA;
            else{
                rootA=rootA->next;
                rootB=rootB->next;
            }
        }
        return nullptr;
    }
    int GetListLength(ListNode *head){
        int length=0;
        ListNode* node=head;
        while(node){
            length++;
            node=node->next;
        }
        return length;
            
    }
};