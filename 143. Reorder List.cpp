/**
143. Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
You must do this in-place without altering the nodes' values.
For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
思路一：使用一个deque去顺序存链表中的所有节点，分别从前面取一次，再从后面取一次，不断链接起来。
直到deque为空。时间复杂度为O(n),空间复杂度为O(n)。

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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        deque<ListNode*> dequ;
        ListNode* ptr=head;
        while(ptr){
            dequ.push_back(ptr);
            ptr=ptr->next;
        }
        bool front=true;
        ListNode* helper= new ListNode(-1);
        ptr=helper;
        while(!dequ.empty()){
            if(front){
                front=false;
                ListNode* temp=dequ.front();
                ptr->next=temp;
                ptr=ptr->next;
                dequ.pop_front();
            }
            else{
                front=true;
                ListNode* temp=dequ.back();
                ptr->next=temp;
                ptr=ptr->next;
                dequ.pop_back();
            }
        }
        ptr->next=nullptr;
        head=helper->next;
        return;
    }
};
//思路2：先使用快慢指针将链表从中间分割成两段，然后后半段就地逆置．之后合并插入到前半段链表即可，时间复杂度O(n)。
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
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head, *p=head, *q=head;
        while(fast->next && fast->next->next)
            slow = slow->next, fast = fast->next->next;
        fast = slow->next, slow->next = NULL;
        p = fast, q = fast->next, fast->next = NULL;
        while(q)
        {
            auto tem = q->next;
            q->next = p;
            p = q, q = tem;
        }
        q = head;
        while(q && p)
        {
            auto tem1 = q->next, tem2 = p->next;
            p->next = q->next;
            q->next = p;
            q = tem1, p = tem2;
        }
    }
};