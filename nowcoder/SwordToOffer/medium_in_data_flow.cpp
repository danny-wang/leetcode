/**
数据流中的中位数 	

题目描述
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

思路：
如果数据加入容器之后，容器是排好序的，那我们可以把整个容器分为两个部分。位于容器左边的数据比右边的数据小。
有两个指针p1, p2, p1指向左部分的做大元素，p2指向右部分的最小元素。
所以需要一个最大堆和一个最小堆。直接利用multiset，multiset是用红黑树实现的。插入的复杂度是n(logn).获得中位数的时间复杂度是o(1).
用最大堆实现左边的数据容器，最小堆实现右边的数据容器。
为了保证两个堆的数据数目之差不大于1，当数据的总数是偶数的时候，把新数据插入最小堆，否则插入最大堆。
注意：如果要插入最大堆，但是这个数比最小堆的堆顶元素大，则把最小堆的堆顶元素插入最大堆，把这个数字插入最小堆，反之亦然。
**/
code:
class Solution {
public:
    void Insert(int num)
    {
        count++;
        is_even=!is_even;
        if(is_even){
            if(!max_heap.empty()){
                int max_val=*(max_heap.begin());
                if(num<max_val){
                    min_heap.insert(max_val);
                    max_heap.erase(max_heap.begin());
                    max_heap.insert(num);
                }
                else{
                    min_heap.insert(num);
                }
            }
            else{
               min_heap.insert(num); 
            }
            
        } 
        else{  //id_odd
            if(!min_heap.empty()){
                int min_val=*(min_heap.begin());
                if(num>min_val){
                    max_heap.insert(min_val);
                    min_heap.erase(min_heap.begin());
                    min_heap.insert(num);
                }
                else{
                    max_heap.insert(num);
                }
            }
            else{
                max_heap.insert(num);
            }
        }
    }

    double GetMedian()
    { 
    	if(is_even){
            if(max_heap.empty())
                return 0;
            if(min_heap.empty())
                return 0;
            double a=*(max_heap.begin());
            double b=*(min_heap.begin());
            return (a+b)/2;
        }
        else{
            if(max_heap.empty())
                return 0;
            return *(max_heap.begin());
        }
    }
private:
    multiset<double,less<double>> min_heap;
    multiset<double,greater<double>> max_heap;
    static int count;
    static bool is_even;
};
int Solution::count=0;
bool Solution::is_even=true;

