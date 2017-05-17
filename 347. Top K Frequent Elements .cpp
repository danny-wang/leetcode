/**
347. Top K Frequent Elements 
Given a non-empty array of integers, return the k most frequent elements.
For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].
Note:
  ● You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
  ● Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
思路1：
  1. hash map 得到<元素，频次>键值对
  2. 新建大小为k的最小堆，保存最大的k个频次，遍历<元素, 频次>，频次大于堆顶元素的，删除堆顶元素，将它入堆，频次小于堆顶的不处理，最后最小堆保存的是出现频次最高的k个
  3. 重新遍历map,凡是频次大于最小堆堆顶元素的就是解。
时间复杂度为O(Nlogk)
**/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty())
            return {};
        unordered_map<int,int> map;
        multiset<int,less<int>> set;
        for(int a : nums){
            if(map.find(a)==map.end())
                map[a]=1;
            else
                map[a]=map[a]+1;
        }
        for(auto ite=map.begin();ite!=map.end();ite++){
            if(set.size()<k)
                set.insert(ite->second);
            else{
                if(ite->second>*(set.begin())){
                    set.erase(set.begin());
                    set.insert(ite->second);
                }
            }
        }
        vector<int> res;
        int min=*(set.begin());
        for(auto ite=map.begin();ite!=map.end();ite++){
            if(ite->second>=min)
            res.push_back(ite->first);
        }
        return res;
    }
};
/**
思路2：
  1. hash，得到<元素，频次>键值对
  2. 因为频次小于n，建散列表，即新建大小为n+1的数组，数组下标为频次，数组内容为有相同频次的键值list，对散列表按下标由大到小遍历，找出k个键值
时间复杂度为O(n);
**/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.empty())
            return {};
        unordered_map<int,int> map;
        multiset<int,less<int>> set;
        for(int a : nums){
            if(map.find(a)==map.end())
                map[a]=1;
            else
                map[a]++;
        }
        vector<vector<int>> hash(nums.size()+1, vector<int>());
        for(auto ite=map.begin();ite!=map.end();ite++){
            hash[ite->second].push_back(ite->first);
        }
        vector<int> res;
        for(int i=nums.size();i>0;i--){
            if(k==0)
                break;
            if(hash[i].empty())
                continue;
            else{
                for(auto i : hash[i]){
                    if(k==0)
                        break;
                    res.push_back(i);
                    k--;
                }
            }
                
        }
        return res;
    }
};