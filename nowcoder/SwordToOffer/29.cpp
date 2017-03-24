连续子数组的最大和 
题目描述
HZ偶尔会拿些专业问题来忽悠那些非计算机专业的同学。今天测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
你会不会被他忽悠住？(子向量的长度至少是1)

思路：动态规划; f(i)表示以第i个数字结尾的字数组的最大和，那么要求出max(f(i))   0<=i<n
f(i)=array[i]   i==0 或者f(i-1)<=0;
f(i)=f(i-1)+array[i]   i!=0并且f(i-1)>0;
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty())
            return 0;
        int result=INT_MIN;
        int pre_result=0;
        int temp=0;
        for(auto i : array){
            if(pre_result<=0)
                temp=i;
            else
                temp=i+pre_result;
            if(temp>result)
                result=temp;
            pre_result=temp;
        }
        return result;
    }
};