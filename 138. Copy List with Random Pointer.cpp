/**
138. Copy List with Random Pointer
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
Return a deep copy of the list.

思路：
此题有两种方法，一种是按照原链表next的顺序依次创建节点，并处理好新链表的next指针，同时把原节点与新节点的对应关系保存到一个hash_map中，然后第二次循环将random指针处理好。这种方法的时间复杂度是O(n)，空间复杂度也是O(n)。

第二种方法则是在原链表的每个节点之后插入一个新的节点，这样原节点与新节点的对应关系就已经明确了，因此不需要用hash_map保存，但是需要第三次循环将整个链表拆分成两个。这种方法的时间复杂度是O(n)，空间复杂度是O(1)。

但是利用hash_map的方法具有其他的优点，如果在循环中加入一个判断，就可以检测出链表中是否有循环；而第二种方法则不行，会陷入死循环。
**/
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head)
            return nullptr;
        unordered_map<RandomListNode*,RandomListNode*> m;
        RandomListNode* ptr=head;
        RandomListNode* copy=new RandomListNode(-1);
        RandomListNode* ptr_to_copy=copy;
        while(ptr){ //按照原链表next的顺序依次创建节点
            RandomListNode* temp=new RandomListNode(ptr->label);
            ptr_to_copy->next=temp;
            ptr_to_copy=ptr_to_copy->next;
            m.insert(make_pair(ptr,temp));//原节点与新节点的对应关系
            ptr=ptr->next;
        }
        ptr_to_copy=copy->next;
        ptr=head;
        while(ptr){  //random指针处理好
            if(ptr->random)
                ptr_to_copy->random=m[ptr->random];
            ptr=ptr->next;
            ptr_to_copy=ptr_to_copy->next;
        }
        return copy->next;
    }
};