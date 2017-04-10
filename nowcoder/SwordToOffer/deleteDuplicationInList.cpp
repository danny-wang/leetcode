/**
删除链表中重复的结点 
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
思路
  1. 需要两个指针，一个指向前一个节点preNode，另一个指向当前节点node，如果遇到相等的节点，node向后移动，preNode不动，直到遇到node和node.next不相等，preNode就可以指向node.next
  2. 注意：链表开头可能就开始有重复的节点，所以新建一个node指向pHead
  **/
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
		ListNode* head=new ListNode(-1);
        head->next=pHead;
        ListNode* pre_node=head;
        ListNode* cur_node=pHead;
        while(cur_node->next!=nullptr){
            if(cur_node->val!=cur_node->next->val){//cur_node if diff about next node 
                pre_node=cur_node;
                cur_node=cur_node->next;
                continue;
            }
            else{
                while(cur_node->next!=nullptr){
                    if(cur_node->val==cur_node->next->val){
                        delete cur_node;
                        cur_node=cur_node->next;
                    }
                    else
                        break;
                }
                if(cur_node->next==nullptr){
                    pre_node->next=nullptr;
                    break;
                }
                else{
                    pre_node->next=cur_node->next;
                    delete cur_node;
                    cur_node=cur_node->next;
                    continue;
                }
                    
            }
        }
        return head->next;
    }
};