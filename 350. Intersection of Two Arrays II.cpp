/**
350. Intersection of Two Arrays II 
Given two arrays, write a function to compute their intersection.
Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
Note:
  ● Each element in the result should appear as many times as it shows in both arrays.
  ● The result can be in any order.
Follow up:
  ● What if the given array is already sorted? How would you optimize your algorithm?
  ● What if nums1's size is small compared to nums2's size? Which algorithm is better?
  ● What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
思路：
用unordered_map存储num1的<数值，次数>键值对，然后遍历num2的每一个元素，遇到出现过的就把map中对应的次数减1。
**/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> map;
        for(auto i : nums1){
            if(map.find(i)==map.end())
                map[i]=1;
            else
                map[i]++;
        }
        vector<int> res;
        for(auto i : nums2){
            if(map.find(i)!=map.end()&& map[i]>0){
                res.push_back(i);
                map[i]--;
            }
        }
        return res;
    }
};