/**
字符串的排列 

题目描述
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:
输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

思路

    1.把字符串分成两部分，一部分是第一个字符，另一个部分是后面其余的字符串
    2.拿第一个字符和后面的字符串依次交换，这是一个递归的过程
    3.注意：在递归里第一次交换是自身和自身的交换，保证不缺少字符串
注意：这里要不能出现重复而且按照字典序输出，所以我选择set中间处理了一下。
**/
class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.empty())
            return {};
        vector<string> result;
        set<string> unique_str;
        Permutaion_helper(unique_str,str,0);
        for(auto i : unique_str)
            result.push_back(i);
        return result;
    }
    void Permutaion_helper(set<string>& result, string str, int i){
        if(i==str.size())
            return;
        for(int j=i;j<str.size();j++){
            char temp=str[i];
            str[i]=str[j];
            str[j]=temp;
            result.insert(str);
            Permutaion_helper(result, str,i+1);
            temp=str[i];
            str[i]=str[j];
            str[j]=temp;
        }
    }
    
};