/**
148. Sort List
解题思路：
表面上看，能够有O(n lgn)时间复杂度的算法为，快速排序，堆排序，归并排序，三者的空间复杂度分别为O(1), O(N),O(N)
所以一开始，我想着用快速排序的方法来解决，但是发现代码很难写出来。于是网上看了一下提示，发现其实方法选错了。应该使用的方法是归并排序。
通常而言，也就是针对数组而言，归并排序的空间复杂度为O(N), 你需要开出O(N)的额外空间来容纳数组，来表示归并后的顺序。但是，对于链表而言，你可以省下这部分空间的开销，你只需要改变节点的next指针的指向，就可以表示新的归并后的顺序了，所以空间复杂度陡然降到了O(1)。
我的代码：

将list分成两个链表（尽量均分）：
使用快慢指针来划分，需要做n/2次比较。
对子链表进行递归排序：
递归次数是：2 * log n
因此这两部分的时间复杂度是：O(n * log n)。
最后，对于两个已排序的子链表，使用归并排序。这一步骤的时间复杂度是：O(n)。
由此可知，总的时间复杂度应该是：O(n * log n)。
注意：当你在函数内部需要修改指针本身的时候，函数传递指针的指针 或者指针的引用
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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){//have 0 or 1 node
            return head;
        }
        else if(head->next->next==nullptr){  //have 2 nodes
            if(head->val > head->next->val){
                swap(head->val,head->next->val);
                return head;
            }
            else
                return head;
        }
        else{  //have 3 or more nodes
            auto slow=head->next;
            auto quick=head->next->next;
            while(quick->next && quick->next->next){
                slow=slow->next;
                quick=quick->next->next;
            }
            auto head2=slow->next;
            slow->next=nullptr;
            auto l=sortList(head);
            auto r=sortList(head2);
            return Merge(l,r);
        }
        
    }
    ListNode* Merge(ListNode* l, ListNode* r){
        ListNode *head=nullptr;
        ListNode *tail=nullptr;
        while(l && r){
            auto &temp= (l->val< r->val? l : r);
            auto node=temp;
            temp=temp->next;
            node->next=nullptr;
            AppendToList(head,tail,node);
        }
        auto temp=(l==nullptr ? r :l);
        AppendToList(head,tail,temp);
        return head;
        
    }
    void AppendToList(ListNode* &head, ListNode* &tail, ListNode* node){
        //cout<<node->val<<endl;
        if(head==nullptr){
            head=tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }
};