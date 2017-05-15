/**
284. Peeking Iterator
Given an Iterator class interface with methods: next() and hasNext(), design and implement a PeekingIterator that support the peek() operation -- it essentially peek() at the element that will be returned by the next call to next().
--------------------------------------------------------------------------------
Here is an example. Assume that the iterator is initialized to the beginning of the list: [1, 2, 3].
Call next() gets you 1, the first element in the list.
Now you call peek() and it returns 2, the next element. Calling next() after that still return 2.
You call next() the final time and it returns 3, the last element. Calling hasNext() after that should return false.
Follow up: How would you extend your design to be generic and work with all types, not just integer?

给定一个派生类，这个派生类只继承了基类的next()和hasNext()方法，现在要求重写派生类的next(),hasNext()和peek()方法
peek()始终取next指针的后一个元素
分析：http://www.cnblogs.com/0summer/p/5831724.html
peek()取的是next指针的后一个元素，并且只有next()和hasNext()两个方法可用，容易发现hasNext()对peek()没有用处，所以对peek()的实现只能通过next()
这是不可避免的，但是产生一个问题就是peek()只是取next后面的值，而不应该移动这个指针的
当然虽然有这个问题，但内部的实现肯定要这么做，那怎么保证对外的接口合法呢
用一个标志位isvis，表示是否用了peek
1.isvis=0，说明没有用peek，系统正常，next指针指向正确的位置，以后的操作该怎样就怎样，比如想调用next()，那就调用next()，取得下一个值并移动指针
2.isvis=1，说明用了peek，系统不正常，next指针指向的是正确位置的下一个位置，如果想调用next()，则不能真的调用next()，因为指针其实已经被peek移动过了
那么返回值该怎么办？用缓存，peek移动指针后保存这个值，这时如果调用next()，直接返回缓存里的值
也就是说isvis=1有两层含义：
1.系统不正常，next指针无需移动
2.缓存里的值可用
**/
// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    has_visited=0;
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(has_visited){
            return cache;
        }
        else{
            has_visited=1;
            cache=Iterator::next();
            return cache;
        }
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(has_visited){
	        has_visited=0;
	        return cache;
	    }
	    else
	        return Iterator::next();
	        
	}

	bool hasNext() const {
	    if(has_visited)
	        return true;
	    else
	        return Iterator::hasNext();
	}
private:
    int cache;
    int has_visited;
};