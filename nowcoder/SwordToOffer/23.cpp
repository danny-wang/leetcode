/**
题目描述
输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。
假设输入的数组的任意两个数字都互不相同。 二叉搜索树的后序遍历序列 
**/

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;
		return Verify(sequence, 0, sequence.size()-1);
    }
    bool Verify(vector<int>& sequence,int left, int right){
        if(left>=right)
            return true;
        int root=sequence[right];
        int i=0;
        for (i=left; i<right; i++){ //判断是否可以分为左右两部分，左边的比root小，右边的比root大
            if(sequence[i]>=sequence[right])
                break;
        }
        for(int j=i;j<right;j++ ){
            if(sequence[j]<sequence[right])
                return false;
        }
        return Verify( sequence, left, i-1) && Verify( sequence, i, right-1);
    }
};
