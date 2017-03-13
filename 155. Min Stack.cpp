/**
155. Min Stack
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
  ● push(x) -- Push element x onto stack.
  ● pop() -- Removes the element on top of the stack.
  ● top() -- Get the top element.
  ● getMin() -- Retrieve the minimum element in the stack.
Example:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.
思路：
要实现最小栈，栈本身就有FILO的性质，而且本身可以实现push(x)，pop()，top()，现在需要实现getMin()这个函数，那我们怎么去保存这个最小值呢？
我的想法是用一个辅助栈min_stack去存最小值，当辅助栈min_stack为空的时候，需要压栈就直接压入，
之后每当有新的元素需要进入的时候，判断这个数字是否小于栈顶元素，如果小就压入，否则在压入一个和栈顶元素一样的元素。
这样实际的栈和min_stack中的元素个数一样，而且min_stack表示当前最小值是多少。弹栈的时候也是一样，分别从两个栈都要弹出栈顶元素。

代码：
**/
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        value_stack.push(x);
        if(min_stack.empty())//为空的时候直接压入
            min_stack.push(x);
        else{               //判断和栈顶元素谁更小，压入小的元素
            int min=min_stack.top();
            if(x<min)
                min_stack.push(x);
            else
                min_stack.push(min);
        }
    }
    
    void pop() {
        value_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return value_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
private:
    stack<int> value_stack;
    stack<int> min_stack;
    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */