/**
栈的压入、弹出序列 
题目描述
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4，5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的） 
思路：注意不能对空栈调用top()，会出现段错误。
**/
class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> helper;
        int indice=0;
        for(int i=0;i<popV.size();i++){
            bool result=AnalyseNumber(popV[i],pushV,indice,helper);
            if(!result)
                return false;
        }
        return true;        
    }
    //number:要判断的数  indice：pushV下一次压入的下标
    bool AnalyseNumber(int number,vector<int>& pushV,int& indice, stack<int>& helper){
        if(!helper.empty() && helper.top()==number){
            helper.pop();
            return true;
        }
        if( indice>=pushV.size())
            return false;
        if( indice<pushV.size()){
            for(;indice<pushV.size();indice++){
                if(pushV[indice]==number){
                    indice++;
                    return true;
                }
                else{
                    helper.push(pushV[indice]);
                }
            }
            return false;
        }
        return false;    
        
    }
};
