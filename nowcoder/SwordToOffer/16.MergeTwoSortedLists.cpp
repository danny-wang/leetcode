/**
合并两个排序的链表 
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。 
思路：两个链表都不空的情况下把小的加入新的链表，直到有一个为空的时候把另一个剩下的全部加入新的链表即可。
**/
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode* one=pHead1;
        ListNode* two=pHead2;
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(one!=nullptr && two!=nullptr){
            if(one->val < two->val){
                temp->next=new ListNode(one->val);
                temp=temp->next;
                one=one->next;
            }
            else{
                temp->next=new ListNode(two->val);
                temp=temp->next;
                two=two->next;
            }
        }
        while(one!=nullptr){
            temp->next=new ListNode(one->val);
            temp=temp->next;
            one=one->next;
        }
        while(two!=nullptr){
            temp->next=new ListNode(two->val);
            temp=temp->next;
            two=two->next;
        }
        return head->next;
    }
};
