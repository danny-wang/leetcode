/**
构建乘积数组 

题目描述
给定一个数组A[0,1,...,n-1],请构建一个数组B[0,1,...,n-1],其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。不能使用除法。
思路：
  1. 若一个个的去相乘，复杂度为O(n2)
  2. 不能用除法，我们可以根据规律创建一个矩阵，把B[]分成两部分，分为A[0]A[i-1]和A[i+1]A[n-1]，
  分别计算这个矩阵中的每行的两部分（就是叠乘），就可以通过一层循环计算出来，复杂度为O(n)
  **/
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int> helper1, helper2, res;
        helper1.push_back(1);
        helper2.push_back(1);
        int temp=1;
        for(int i=0;i<A.size()-1;i++){
            temp*=A[i];
            helper1.push_back(temp);
        }
        temp=1;
        for(int i=A.size()-1;i>0;i--){
            temp*=A[i];
            helper2.push_back(temp);
        }
        for(int i=0;i<A.size();i++)
            res.push_back(helper1[i]*helper2[A.size()-1-i]);
        return res;
    }
};