/**219. Contains Duplicate II
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.
思路：要求重复元素的半径不大于K
将所有的相同元素的下标存起来，判断其中是否有小于k的
**/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        bool have_duplicate=false;
        map<int,vector<int>> helper; //key is the number appears in vector, value is indices
        for(int i=0; i<nums.size();i++){
            if(helper.find(nums[i])!=helper.end()){
                have_duplicate=true;
                helper[nums[i]].push_back(i);
            }
            else{
                vector<int> temp={i};
                helper.insert(make_pair(nums[i],temp));
            }
        }
        int abs_diff=INT_MAX;
        for(auto ite=helper.begin();ite!=helper.end();ite++){
            if((ite->second).size()>1){
                for(int i=1;i<(ite->second).size();i++){
                    if((ite->second)[i]-(ite->second)[i-1]<abs_diff)
                    abs_diff=(ite->second)[i]-(ite->second)[i-1];
                }
                
            }
        }
        if(have_duplicate==false)
            return false;
        if(abs_diff<=k)
            return true;
        else
            return false;
        
    }
};
//思路二：map中元素值为Key，元素索引下表为Value。所以在找到重复的情况下，可以判断下标差是否小于等于K。如果大于K，则修改已在map中元素对应的value，即下标。
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         map<int, int>int_map;
         map<int,int>::iterator iter;
        for (int i = 0; i<nums.size(); i++) {
            if((iter=int_map.find(nums[i]) )!= int_map.end() ){
                if (i - iter->second <= k) {
                    return true;
                }else{
                    int_map.erase(iter);
                }
            }
            int_map.insert(pair<int, int>(nums[i], i));
        }
        return false;
    }
};