 /*
 56. Merge Intervals 

Given a collection of intervals, merge all overlapping intervals.
For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
Subscribe to see which companies asked this question.
思路：
题目要求对区间进行合并，首先必须对区间按照左边元素的大小进行排序，然后对排序后的数组进行遍历，合并。
然后对每两个interval（记为a,b），判断是否需要合并。
如果不需要合并（没有交集），考虑下一个
如果需要合并（有交集）a.end>b.start && a.end<b.end，

这题本身是不难的，但是有两个细节：
1、compare函数中，如果是升序，必须是<而不是<=
解释：参考http://www.cplusplus.com/reference/list/list/sort/，比较必须产生strick weak ordering。
对于strick weak ordering 可以参考http://stackoverflow.com/questions/979759/operator-and-strict-weak-ordering/981299#981299
的详细说明。
总之，如果a,b不等，那么compare(a,b)和compare(b,a)其中之一为true，另一为false。
如果a,b相等，则都应该为false。
2、compare函数必须声明为静态成员函数或者全局函数，不能作为普通成员函数
解释：非静态成员函数是依赖于具体对象的，而std::sort这类函数是全局的，因此无法在sort中调用非静态成员函数。
可以把compare改成静态或者全局函数，使之不依赖于具体对象。
*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.empty())
            return {};
        int length=intervals.size();
        std::sort(intervals.begin(),intervals.end(),comp);
        vector<Interval>::iterator iter=intervals.begin();
        while(iter!=(intervals.end()-1)){
            vector<Interval>::iterator iter_next=(iter+1);
            if(iter->end >=iter_next->start){
                if(iter->end < iter_next->end){
                    iter->end=iter_next->end;
                }
                intervals.erase(iter_next);
                continue;
            }
            else
                iter++;
        }
        return intervals;
    }
    static bool comp(const Interval &a,const Interval &b)
    {
        return a.start<b.start;
    }
};