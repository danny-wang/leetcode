/**
349. Intersection of Two Arrays 
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
Note:
  ● Each element in the result must be unique.
  ● The result can be in any order.
思路1：
用unordered_set去存储array中的所有元素，unordered_set会自动去除重复。然后查看两个unordered_set中是否有重复元素,时间复杂度O（n）.
**/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        unordered_set<int> b;
        for(int i : nums1)
            a.insert(i);
        for(int i : nums2)
            b.insert(i);
        vector<int> res;
        for(auto i=a.begin();i!=a.end();i++){
            if(b.find(*i)!=b.end())
                res.push_back(*i);
        }
        return res;
    }
};
//思路2：
//简单hashtable, 先把一个数组放到hashtable中, 然后查另外一个数组, 如果碰到相同的就加入结果集合, 并且删除其hashtable.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        for(int i : nums1)
            a.insert(i);
        vector<int> res;
        for(int i : nums2){
            if(a.find(i)!=a.end()){
                res.push_back(i);
                a.erase(i);
            }
        }
        return res;
    }
};