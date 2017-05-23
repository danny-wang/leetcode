/**
380. Insert Delete GetRandom O(1) 
Design a data structure that supports all following operations in average O(1) time.
  1. insert(val): Inserts an item val to the set if not already present.
  2. remove(val): Removes an item val from the set if present.
  3. getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
Example:
// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();

思路: 要在O(1)的时间内完成插入, 删除, 取随机元素. 用链表保存元素可以在O(1)内完成插入和删除, 但是无法在O(1)随机元素. 
所以需要一个可以随机存取的容器. 如果使用数组的话可以在O(1)内完成插入和随机, 但是删除无法在O(1)完成, 
但是如果用另外一种删除方式, 即把要删除的元素与最后的元素交换位置, 而删除最后一个元素就可以在O(1)完成. 
这样的话还需要一个hash表来记录元素在数组的位置, 这样才可以来O(1)取到这个元素, 并移动到尾部. 
还需要注意的是在删除一个元素的时候与另外一个元素交换了位置, 所以在hash表中还需要将另外一个元素的位置更新.
**/
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.find(val)!=map.end())
            return false;
        store.push_back(val);
        map[val]=store.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(map.find(val)==map.end())
            return false;
        int index=map[val];
        swap(store[index],store[store.size()-1]);
        map[store[index]]=index;
        map.erase(store[store.size()-1]);
        store.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return store[rand()%store.size()];
    }
private:
    vector<int> store;
    unordered_map<int,int> map;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */