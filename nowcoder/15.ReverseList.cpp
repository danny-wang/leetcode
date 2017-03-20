/**
反转链表 
题目描述
输入一个链表，反转链表后，输出链表的所有元素。 
思路：三个指针，注意链表为空和只有一个节点的时候。注意什么时候到达最后一个节点
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
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead==nullptr || pHead->next==nullptr)
            return pHead;
        ListNode* slow=pHead;
        ListNode* cur=pHead->next;
        ListNode* quick=pHead->next->next;
        slow->next=nullptr;
        while(cur!=nullptr){
            cur->next=slow;
            slow=cur;
            cur=quick;
            if(quick!=nullptr)
                quick=quick->next;
        }
        return slow;
    }
};
