/**
复杂链表的复制 
题目描述
输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），
返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空） 

在不使用辅助空间的情况下实现O(N)的时间效率。

第一步：根据原始链表的每个结点N创建对应的N'，然后将N‘通过pNext接到N的后面；

第二步：设置复制出来的结点的pSibling。假设原始链表上的N的pSibling指向结点S，
那么其对应复制出来的N'是N->pNext指向的结点，同样S'也是结点S->pNext指向的结点。

第三步：把长链表拆分成两个链表，把奇数位置的结点用pNext连接起来的就是原始链表，
把偶数位置的结点通过pNext连接起来的就是复制链表。
**/
/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        //复制每一个节点
        if(pHead==nullptr)
            return pHead;
        RandomListNode* head=pHead;
        RandomListNode* first=pHead;
        RandomListNode* second=pHead->next;
        while(first){
            RandomListNode* copyer=new RandomListNode(first->label);
            copyer->next=first->next;
            first->next=copyer;
            first=second;
            if(first)
                second=first->next;
        }
        //给复制出来的节点赋值random
        first=pHead;
        second=pHead->next;
        while(second){
            if(first->random)
                second->random = first->random->next;
            first = second->next;
            if(first)
                second=first->next;
            else
                second=nullptr;
        }
        //拆分成两个链表。奇数位置上的组成原始链表，偶数位置上的组成复制出的链表
        RandomListNode* pNode=pHead; 
        RandomListNode* pClonedHead=NULL;
        RandomListNode* pClonedNode=NULL;
        //初始化
        if(pNode!=NULL){         
            pClonedHead=pClonedNode=pNode->next;     
            pNode->next=pClonedNode->next;         
            pNode=pNode->next;                
        }
        //循环
        while(pNode!=NULL)        {       
            pClonedNode->next=pNode->next;      
            pClonedNode=pClonedNode->next;      
            pNode->next=pClonedNode->next;      
            pNode=pNode->next;       
        }                  
        return pClonedHead;
             
    }
};