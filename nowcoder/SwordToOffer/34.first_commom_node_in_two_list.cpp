/**
两个链表的第一个公共结点

题目描述
输入两个链表，找出它们的第一个公共结点。

思路：使用辅助栈
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode* ptr1=pHead1;
        ListNode* ptr2=pHead2;
        stack<ListNode*> first;
        stack<ListNode*> second;
        while(ptr1){
            first.push(ptr1);
            ptr1=ptr1->next;
        }
        while(ptr2){
            second.push(ptr2);
            ptr2=ptr2->next;
        }
        ListNode* result=nullptr;
        while(!first.empty() && !second.empty()){
            if(first.top()==second.top()){
                result=first.top();
                first.pop();
                second.pop();
                continue;
            }
            else
                break;
        }
        return result;
       
    }
};