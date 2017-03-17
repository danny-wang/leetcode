/**
题目描述
输入一个链表，从尾到头打印链表每个节点的值。 
思路：用一个stack去存所有的节点，栈顶的就是最后一个，不断弹栈即可。
**/
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        if(head==nullptr)
            return {};
        stack<ListNode*> temp;
        vector<int> result;
        while(head){
            temp.push(head);
            head=head->next;
        }
        while(!temp.empty()){
            result.push_back(temp.top()->val);
            temp.pop();
        }
        return result;
        
    }
};
