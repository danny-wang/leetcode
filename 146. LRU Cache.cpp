/**
146. LRU Cache
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Follow up:
Could you do both operations in O(1) time complexity?
Example:
LRUCache cache = new LRUCache( 2 // capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4


解题思路：
1、用一个hash表来维护结点的位置关系，也就是hash表的key就是资源本身的key，value是资源的结点（包含key和value的信息）。
2、把结点维护成一个双向链表构成的队列，这样子如果我们要访问某一个结点，那么可以通过hash表和key来找到结点，从而取到相应的value。而当我们想要插入结点时，我们还是通过hash表找到结点，然后通过双向链表和队列的头结点把自己插入到队头，如果超过了容量上限，就要删除队尾的节点。
3、通过hash表访问结点我们可以认为是O(1)的操作（假设hash函数足够好），然后双向链表的插入删除操作也是O(1)的操作。如此我们便实现了用O(1)时间来完成所有LRU cache的操作。空间上就是对于每一个资源有一个hash表的的项以及一个对应的结点（包含前后指针和资源的<key, value>）
注意：
1、链表为空时，插入节点
2、删除的节点在头，在尾或者在中间
3、插入的节点若键已存在，则替换其值，再将其从链表中删除后插入链表头部
**/
struct Node{
	int key;
	int value;
	Node* pre;
	Node* next;
	Node(int k, int v) :key(k), value(v),pre(nullptr),next(nullptr){
	}
};
class LRUCache{
public:
	LRUCache(int cap){
		capacity = cap;
		head = nullptr;
		tail = nullptr;
	}
	int get(int key){
		if (hash.find(key) != hash.end()){
			put(key, (hash.find(key)->second)->value);
			return (hash.find(key)->second)->value;
		}
		else
			return -1;
	}
	void put(int key, int value){
		if (capacity < 1)
			return;
		if (hash.size() == 0){
			Node* ptr = new Node(key, value);
			head = ptr;
			tail = ptr;
			hash.insert(make_pair(key, ptr));
			return;
		}
		if (hash.find(key) != hash.end()){ //find in list
			if ((hash.find(key)->second) == head){// this node is head
			    head->value=value;
				return;
			}
			else
				((hash.find(key)->second)->pre)->next = (hash.find(key)->second)->next;
			if ((hash.find(key)->second) == tail)
				tail = ((hash.find(key)->second)->pre);
			else
				((hash.find(key)->second)->next)->pre = (hash.find(key)->second)->pre;
			(hash.find(key)->second)->next = head;
			head->pre = (hash.find(key)->second);
			(hash.find(key)->second)->pre = nullptr;
			head = (hash.find(key)->second);
		    head->value=value;
		}
		else{ //not find in list
			Node* ptr = new Node(key, value);
			ptr->next = head;
			head->pre = ptr;
			head = ptr;
			hash.insert(make_pair(key, ptr));
			if (hash.size() > capacity){ //need to delete the least recently used one, which is in pointed by tail
				int delete_key = tail->key;
				Node* new_tail = tail->pre;
				new_tail->next = nullptr;
				delete tail;
				tail = new_tail;
				hash.erase(delete_key);
			}			
		}
	}
private:
	unordered_map<int, Node*> hash;
	Node* head;
	Node* tail;
	int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */