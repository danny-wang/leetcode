/**
382. Linked List Random Node
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
Follow up:
What if the linked list is extremely large and its length is unknown to you? Could you solve this efficiently without using extra space?
Example:
// Init a singly linked list [1,2,3].
ListNode head = new ListNode(1);
head.next = new ListNode(2);
head.next.next = new ListNode(3);
Solution solution = new Solution(head);

// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.
solution.getRandom();
思路1：
这道题给了我们一个链表，让我们随机返回一个节点，那么最直接的方法就是先统计出链表的长度，并且将所有节点的指针存在在一个vector中，然后根据长度随机生成一个位置t,然后去vector[t]位置指针对应的数据即可，初始化类的时间复杂度为O(n),取随机数的时间复杂度为O(1).空间复杂度为O(n).
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) : size(0) {
        ListNode* temp=head;
        while(temp){
            point.push_back(temp);
            temp=temp->next;
            size++;
        }
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        if(size==0)
            return -1;
        int index=rand()%size;
        return (point[index])->val;
    }
private:
    vector<ListNode*> point;
    int size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
/**
思路2：
Follow up中说链表可能很长，我们没法提前知道长度，这里用到了著名了水塘抽样的思路，
其原理为一个个的对元素取样, 在遍历到每个元素的时候可以有个概率选取, 或者不选取. 因为是随机选取一个数, 所以相当于水池的容量是1. 相对简单一些.
那么如何确保对于每个元素都有相等的概率呢? 这里用到了概率论的知识, 在遍历到第i个数时设置选取这个数的概率为1/i, 然后来证明一下每个数被选到的概率: 对于第一个数其被选择的概率为1/1*(1-1/2)*(1-1/3)*(1-1/4)*...*(1-1/n) = 1/n, 其中(1-1/n)的意思是不选择n的概率, 也就是选择1的概率乘以不选择其他数的概率. 对于任意一个数i来说, 其被选择的概率为1/i*(1-1/(i+1))*...*(1-1/n), 所以在每一个数的时候我们只要按照随机一个是否是i的倍数即可决定是否取当前数即可.
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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        ListNode* temp=head;
        int count=1;
        int res=0;
        while(temp){
            if(rand()%count==0)
                res=temp->val;
            temp=temp->next;
            count++;
        }
        return res;
    }
private:
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */