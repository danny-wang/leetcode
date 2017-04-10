/**
滑动窗口的最大值 

题目描述
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
思路：
这实际上可以看成是TCP/IP中差错控制中滑动窗口的算法实现了。由于每次窗口大小是固定的，所以可以创建一个指针用于指向当前窗口的第一个值，而且位置该值是当前窗口的最大值的下标。这么做的好处在于每次窗口移动只需要从第一个位置取值就可以，时间复杂度是O(1)。那么具体需要在获取每个窗口的值得时候与队列中（需要创建一个队列用于保存每个窗口最大值的下标）的队尾指针的元素进行比较，如果比当前遍历到的元素小的话，需要把队尾元素移除，因为我们需要获得的是最大值。这样一直遍历到最后一个元素，就把每个窗口的最大值获取到了。
下面是具体的实现代码
**/
class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> window;
        deque<int> index; //indice of nodes which have possibility to be the biggest
        if(num.size()<size || size<1)
            return {};
        for(int i=0;i<size;i++){
            while(!index.empty() &&num[index.back()]<=num[i])
                index.pop_back();
            index.push_back(i);
        }
        for(int i=size;i<num.size();i++){
            window.push_back(num[index.front()]);
            while(!index.empty() && num[index.back()]<=num[i])
                index.pop_back();
            index.push_back(i);
            if(!index.empty()&& index.front()<=(i-size))
                index.pop_front();
        }
        window.push_back(num[index.front()]);
        return window;
    }
};