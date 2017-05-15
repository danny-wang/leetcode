/**
229. Majority Element II
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

分析：
因为要找出的是出现次数大于⌊ n/3 ⌋的元素，因此最多只可能存在两个这样的元素，而且要求O(1)的空间复杂度，因此只能使用摩尔投票法。
首先我们遍历一遍数组找出两个候选元素，接着再遍历一遍数组，判断候选元素的出现次数是否超过三分之一即可。
接着我们确定两个候选元素，当有候选元素未设置时，先将当前遍历到的元素设置为候选元素。若
遍历到的元素和其中一个候选元素相等时，候选元素的计数器加一，若和两个候选元素都不相等，则两个候选元素的计数器都减一。
其实摩尔投票法的本质就是将元素进行分组，每组中都是不同的元素，最后剩下的那些元素就可能是出现次数最多的元素。
例如上文中的解法就是将所有元素分成若干个三元组，每组中的数字都是各不相同的。如果一个元素出现的次数超过了三分之一，
那么它必然在剩下的元素中存在，因此它能成为候选元素。

  1. 遍历数组，当数组中元素和num1或者num2相同，对应的counter1或者counter2加1；
  2. 如果counter1或counter2为0，将遍历到的该元素赋给num1或者nums2；
  3. 否则counter1和counter2都减1。
其中第3步是算法的核心，就是每次删除三个不相同的数，最后留下的一定是出现次数超过1/3的数，这个思想可以推广到出现次数超过1/k次的元素有哪些。
**/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int a=INT_MIN;
        int b=INT_MIN;
        int a_num=0;
        int b_num=0;
        for(int i=0;i<nums.size();i++){
            if(a_num!=0 && nums[i]==a)
                a_num++;
            else if(b_num!=0 && nums[i]==b)
                b_num++;
            else if(a_num==0){
                a=nums[i];
                a_num=1;
            }
            else if(b_num==0){
                b=nums[i];
                b_num=1;
            }
            else{ //消去一个三元组
                a_num--;
                b_num--;
            }
        }
        a_num=0;
        b_num=0;
        for(auto i : nums){
            if(i==a)
                a_num++;
            else if(i==b)
                b_num++;
        }
        vector<int> result;
        if(a_num>nums.size()/3)
            result.push_back(a);
        if(b_num>nums.size()/3)
            result.push_back(b);
        return result;
    }
};