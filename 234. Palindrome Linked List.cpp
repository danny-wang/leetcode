/**
Given a singly linked list, determine if it is a palindrome.
Follow up:
Could you do it in O(n) time and O(1) space?

判断一个单向链表是否是回文链表，要求O（n）的时间复杂度和O（1）的空间复杂度。
算法有以下几种：
1、遍历整个链表，将链表每个节点的值记录在数组中，再判断数组是不是一个回文数组，时间复杂度为O（n），但空间复杂度也为O（n），不满足空间复杂度要求。
2、利用栈先进后出的性质，将链表前半段压入栈中，再逐个弹出与链表后半段比较。时间复杂度O（n），但仍然需要n/2的栈空间，空间复杂度为O（n）。
3、反转链表法，将链表后半段原地翻转，再将前半段、后半段依次比较，判断是否相等，时间复杂度O（n），空间复杂度为O（1）满足题目要求。
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
    bool isPalindrome(ListNode* head) {
        //如果链表为空或者只有一个，一定是回文
        if(head==nullptr || head->next==nullptr)
            return true;
        //快慢指针法，找到链表的中间元素
        ListNode* slow, *quick;
        slow=quick=head;
        while(quick && quick->next){
            slow=slow->next;
            quick=quick->next->next;
        }
        //链表一共有奇数个元素
        if(quick){  
            slow=reverse(slow->next);
        }
        //链表一共有偶数个元素
        else{
            slow=reverse(slow);
        }
        //已经反转了后一半链表，比较是否和前一半一致
        while(slow){
            if(slow->val != head->val)
                return false;
            slow=slow->next;
            head=head->next;
        }
        return true;
    }
    //反转链表
    ListNode* reverse(ListNode* p){
        if(p==nullptr || p->next==nullptr)
            return p;
        ListNode *pre=p;
        ListNode *cur=p->next;
        ListNode *next=nullptr;
        pre->next=nullptr;
        while(cur){
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
        
    }
};
