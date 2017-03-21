/**
调整数组顺序使奇数位于偶数前面
时间限制：1秒 空间限制：32768K 热度指数：15850
本题知识点： 数组
算法知识视频讲解
题目描述
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
思路： 分别按顺序获得所有的奇数和偶数，然后把偶数放在奇数后即可。
**/

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> odd_number;
        vector<int> even_number;
        for(int i=0; i<array.size(); i++){
            if(array[i]&0x1==1)  //odd number
                odd_number.push_back(array[i]);
            else
                even_number.push_back(array[i]);
        }
        for(int i=0; i<even_number.size();i++){
            odd_number.push_back(even_number[i]);
        }
        array=odd_number;
        return;
    }
};

