/**
147. Insertion Sort List
Sort a linked list using insertion sort.

解题思路：
插入排序。
初始设定，第一个节点是已排序的部分。从第二个节点开始是未排序的部分。
每次从未排序部分取出最前面的一个节点，把它插入已排序的序列中。
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head)
            return nullptr;
        ListNode* sorted=new ListNode(INT_MIN);
        sorted->next=head;
        ListNode* unsorted=head->next;
        head->next=nullptr;
        while(unsorted){
            auto temp=sorted;
            for(;temp->next!=nullptr;temp=temp->next){
                if(temp->next->val <= unsorted->val)
                    continue;
                else
                    break;
            }
            auto a=temp->next;
            temp->next=unsorted;
            unsorted=unsorted->next;
            temp->next->next=a;
        }
        return sorted->next;
    }
};