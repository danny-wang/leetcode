/**
381. Insert Delete GetRandom O(1) - Duplicates allowed 
Design a data structure that supports all following operations in average O(1) time.
Note: Duplicate elements are allowed.
  1. insert(val): Inserts an item val to the collection.
  2. remove(val): Removes an item val from the collection if present.
  3. getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:
// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();
由于存在重复元素，并且各元素随机取到的概率和元素数量呈线性相关，所以为了满足随机取O(1)的时间复杂度，这里将所有插入的数字均存储下来。
很自然在存储各元素下标的Hash Table中需要再用vector来存储所有相同元素的下标。数据存储形式确定后实现起来就比较简单了，插入操作没什么难度不再赘述；
删除操作只删除多个相同元素中的一个，这里将Hash Table中该元素所有下标的最后一个和存储所有数据的数组中最后一个元素交换，
然后删除数组最后一个元素（注意判断两者是否相等），其他更新Hash Table的操作不再详细说明，有了第380题的基础相信不难理解，
如果删除元素所对应的下标数组为空则在Hash Table中删除该元素；随机取和第380相同，不再详述。具体代码：
**/
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool sig=true;
        if(map.find(val)!=map.end())
            sig=false;;
        store.push_back(val);
        map[val].insert(store.size()-1);
        if(sig)
            return true;
        else
            return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(map.find(val)==map.end())
            return false;
        int index=*(map[val].begin());
        if(store[index]==store[store.size()-1]){
            map[val].erase(store.size()-1);
            if(map[val].empty())
                map.erase(val);
            store.pop_back();
            return true;
        }
        else{
            swap(store[index],store[store.size()-1]);
            map[store[index]].erase(store.size()-1);
            map[store[index]].insert(index);
            map[store[store.size()-1]].erase(index);
            if(map[store[store.size()-1]].empty())
                map.erase(store[store.size()-1]);
            store.pop_back();
            return true;
        }
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return store[rand()%store.size()];
    }
private:
    vector<int> store;
    unordered_map<int,unordered_set<int>> map;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
