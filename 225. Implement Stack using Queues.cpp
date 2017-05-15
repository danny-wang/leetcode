/**
225. Implement Stack using Queues
Implement the following operations of a stack using queues.
  ● push(x) -- Push element x onto stack.
  ● pop() -- Removes the element on top of the stack.
  ● top() -- Get the top element.
  ● empty() -- Return whether the stack is empty.
Notes:
  ● You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
  ● Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
  ● You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
思路：因为之前见过使用栈来实现队列，它是使用两个栈来实现队列，于是就想能不能使用两个队列来实现栈，结果发现还真是可以。
定义两个队列作为自定义栈的成员变量，当需要插入元素时找到不为空的那个队列将元素插入进行，弹出元素时将不为空的那个队列的前n-1（n为队列中元素的大小）的元素弹出并插入为空的那个队列中，再弹出最后一个元素，
这样插入的时间复杂度是O(1),弹出最后一个元素和获取最后一个元素的时间复杂度是O(n)，图示如下： 
**/

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
       use_q=true; 
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(use_q){
            q.push(x);
        }
        else{
            shadow_q.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(use_q){
            int size=q.size();
            for(int i=0;i<size-1;i++){
                shadow_q.push(q.front());
                q.pop();
            }
            int temp=q.front();
            q.pop();
            use_q=false;
            return temp;
        }
        else{
            int size=shadow_q.size();
            for(int i=0;i<size-1;i++){
                q.push(shadow_q.front());
                shadow_q.pop();
            }
            int temp=shadow_q.front();
            shadow_q.pop();
            use_q=true;;
            return temp;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(use_q){
            int size=q.size();
            for(int i=0;i<size-1;i++){
                shadow_q.push(q.front());
                q.pop();
            }
            int temp=q.front();
            shadow_q.push(q.front());
            q.pop();
            use_q=false;
            return temp;
        }
        else{
            int size=shadow_q.size();
            for(int i=0;i<size-1;i++){
                q.push(shadow_q.front());
                shadow_q.pop();
            }
            int temp=shadow_q.front();
            q.push(shadow_q.front());
            shadow_q.pop();
            use_q=true;;
            return temp;
        }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(use_q)
            return q.empty();
        else
            return shadow_q.empty();
    }
    private:
    queue<int> q;
    queue<int> shadow_q;
    bool use_q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

// 但是在Discuss中看到一种更好的解法，它只需要使用一个队列就可以了。并且代码量大大减少了。
// 具体做法每往队列中插入一个元素，都将它前面的元素弹出并重新插入队列中，这样就能保证最后插入队列的元素始终在队列的最前端，比如插入a,b,c,d这四个元素，队列中元素的顺序依次为a,ab,abc,abcd，
// 这样插入的时间复杂度是O(n)，弹出和获取最后一个元素的时间复杂度是O(1)，是不是很奇妙？图示如下：
// C++代码如下： 
// runtime:0ms 

class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        q.push(x);
        for(int i=0;i<q.size()-1;i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        q.pop();
    }

    // Get the top element.
    int top() {
        return q.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q.empty();
    }

    private:
    queue<int> q;
};
