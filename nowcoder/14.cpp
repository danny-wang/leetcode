/**
链表中倒数第k个结点 
题目描述
输入一个链表，输出该链表中倒数第k个结点。 
思路：快慢指针，注意访问空指针会崩溃
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr || k==0)
            return nullptr;
    	ListNode* quick_ptr=pListHead;
        ListNode* slow_ptr=pListHead;
        for(int i=1;i<k;i++){
            if(quick_ptr->next==nullptr)
                return nullptr;
            else
                quick_ptr=quick_ptr->next;
        }
        while(quick_ptr->next!=nullptr){
            quick_ptr=quick_ptr->next;
            slow_ptr=slow_ptr->next;
        }
        return slow_ptr;
    }
};
