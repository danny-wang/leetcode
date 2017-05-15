/**
220. Contains Duplicate III
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference betweennums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
思路：
总得思路就是：“滑动窗口”+set。 　我们只需要维持一个大小为K的窗口,判断窗口是是否有满足以下条件成立的X。
|x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
注意：因为有溢出的问题，所以需要把类型提升到long long 
**/
 bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    set<int> window; // set is ordered automatically 
    for (int i = 0; i < nums.size(); i++) {
        if (i > k) window.erase(nums[i-k-1]); // keep the set contains nums i j at most k
        // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
        auto pos = window.lower_bound(nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t 
        // x - nums[i] <= t ==> |x - nums[i]| <= t    
        if (pos != window.end() && *pos - nums[i] <= t) return true;
        window.insert(nums[i]);
    }
    return false;
}


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k <1)
            return false;
        set<long long> s;
        for(int i =0; i < nums.size(); i++){
            if(i>k)
                s.erase(nums[i-k-1]);
            auto ite=s.lower_bound((long long)nums[i]-t);
            if(ite!=s.end() && static_cast<long long>(t)+nums[i]>=*ite)
                return true;
            s.insert(nums[i]);
        }
        return false;       
    }
};