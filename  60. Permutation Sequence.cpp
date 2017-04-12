/**
60. Permutation Sequence
The set [1,2,3,…,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):
  1. "123"
  2. "132"
  3. "213"
  4. "231"
  5. "312"
  6. "321"
Given n and k, return the kth permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
Subscribe to see which companies asked this question.
Have you met this question in a real interview?

解题思路：
这题不可以用递归的解法，否则不管怎么优化都会超时，这题时间卡得很紧啊。。。之前一直在优化递归，从几百毫秒优化到 9 毫秒依然不行。遂放弃，上网学习大神的解法，才发现这题是有数学技巧的。
具体来说是：
n 个数字有 n！种全排列，每种数字开头的全排列有 (n - 1)!（n！/ n）种。
所以用 k / (n - 1)! 就可以得到第 k 个全排列是以第几个数字开头的。
用 k % (n - 1)! 就可以得到第 k 个全排列是某个数字开头的全排列中的第几个。
这又变成了最初的问题设置。
对于以某个数字开头的全排列（第一个数字固定后的全排列，不再理会第一个数字），它有 (n - 1)! 种全排列，那么这些全排列中，每个数字开头的全排列有 (n - 2)! （(n-1)! / (n-1)）。
依次类推。
在代码中为了使每次选中的数字不会重复。先用一个数组记录下所有数字（1 到 n），每次使用了某个数字后，就把该数字从数组中移除。
上述我们提到的“第 k 个全排列是以第几个数字开头“，这”第几个数字“并不是指该数字本身，而是数组中的”第几个数字“。
**/
class Solution {
public:
    string getPermutation(int n, int k) {
        if(n<1)
            return "";
        vector<int> all_val;
        for(int i=0;i<9;i++)
            all_val.push_back(i+1);
        vector<int> factorial={1};  //factorial[i] stores i!
        for(int i=1;i<=9;i++)
            factorial.push_back(i*factorial[i-1]);
        if(k>factorial[9] || k<1)
            return "";
        int count=n;
        int factor=n-1;
        k=k-1;
        vector<int> medium_res;
        while(count){
            int temp= k/factorial[factor];
            medium_res.push_back(all_val[temp]);
            all_val.erase(all_val.begin()+temp);
            k=k%factorial[factor];
            factor--;
            count--;
        }
        stringstream ss;
        string res;
        for(auto i : medium_res)
            ss<<i;
        res=ss.str();
        return res;
        
    }
};