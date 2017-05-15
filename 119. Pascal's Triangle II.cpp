// 119. Pascal's Triangle II
// Given an index k, return the kth row of the Pascal's triangle.
// For example, given k = 3,
// Return [1,3,3,1].
// Note:
// Could you optimize your algorithm to use only O(k) extra space?
// 思路：用一个队列去存每一行的所有数值，下一行的数值可以通过上一行的计算出来。
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        queue<int> queue;
        if(rowIndex<0)
            return {};
        if(rowIndex==0)
            return {1};
        queue.push(1);
        for(int i=1;i<=rowIndex;i++){
            int size=i;
            queue.push(1);
            int temp=queue.front();
            queue.pop();
            size--;
            while(size>0){
                if(size>0){
                    int b=queue.front();
                    queue.pop();
                    queue.push(b+temp);
                    temp=b;
                    size--;
                }
            }
            queue.push(1);
        }
        vector<int> result;
        while(!queue.empty()){
            int temp=queue.front();
            result.push_back(temp);
            queue.pop();
        }
        return result;
    }
};