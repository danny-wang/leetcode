/**
链表中环的入口结点

题目描述
一个链表中包含环，请找出该链表的环的入口结点。
思路：
1、哈希表
遍历整个链表，并将链表结点存入哈希表中（这里我们使用容器set），如果遍历到某个链表结点已经在set中，那么该点即为环的入口结点；
2、两个指针
如果链表存在环，那么计算出环的长度n（利用快慢指针，找到他们相遇的点，这个点一定在环内，然后计算环的长度），然后准备两个指针pSlow，pFast，pFast先走n步，然后pSlow和pFase一块走，当两者相遇时，即为环的入口处；
3、改进
如果链表存在环，我们无需计算环的长度n，只需在相遇时，让一个指针在相遇点出发，另一个指针在链表首部出发，然后两个指针一次走一步，当它们相遇时，就是环的入口处。（这里就不说明为什么这样做是正确的，大家可以在纸上推导一下公式）
思路2的代码实现：
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
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==nullptr)
            return nullptr;
		int length=LengthOfLoop(pHead);
        if (length==0)
            return nullptr;
        ListNode* quicker=pHead;
        ListNode* slower=pHead;
        for(int i=0;i<length;i++){
            quicker=quicker->next;
        }
        while(quicker!=slower){
            quicker=quicker->next;
            slower=slower->next;
        }
		return quicker;
    }
    int LengthOfLoop(ListNode* pHead){
        ListNode* quicker=nullptr;
        ListNode* slower=nullptr;
        if(pHead!=nullptr && pHead->next!=nullptr){
            quicker=pHead->next->next;
            slower=pHead->next;
        }
        else
            return 0;
        while(quicker!=slower){ //find the node they meet each other
            if(quicker!=nullptr && quicker->next!=nullptr)
            	quicker=quicker->next->next;
            else
                return 0;
            if(slower!=nullptr )
            	slower=slower->next;
            else
                return 0;
        }
        ListNode* ptr=quicker;
        int length=1;
        quicker=quicker->next;
        while(quicker!=ptr){  //find out the length
            length++;
            quicker=quicker->next;
        }
        return length;
    }
};