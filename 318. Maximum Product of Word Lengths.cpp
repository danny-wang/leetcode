/**
318. Maximum Product of Word Lengths
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".
Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".
Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.

思路1：用一个矩阵保存两两是否相同，下一次对于相同的元素计算长度乘积。复杂度是O(n^2)的，毫无疑问超时了 69 / 174 test cases passed.  Time Limit Exceeded
**/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty())
            return 0;
        vector<vector<char>> mid(words.size(),vector<char>(words.size(),'0'));
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(i==j)
                    continue;
                unordered_set<char> set_a;
                for(char x : words[i])
                    set_a.insert(x);
                bool is_same=false;
                for(char x : words[j]){
                    if(set_a.find(x)!=set_a.end()){
                        is_same=true;
                        break;
                    }
                }
                if(!is_same)
                    mid[i][j]='1';
            }
        }
        vector<int> length;
        for(int i=0;i<words.size();i++)
            length.push_back(words[i].size());
        int result=0;
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if(mid[i][j]=='1'){
                    if(length[i]*length[j]>result)
                        result=length[i]*length[j];
                }    
            }
        }
        return result;
    }
};
/**
别人的分析：
漂亮，这种位处理方法对于字符的处理似乎很常用，在前面某个题目见过这种做法！
根据题目的描述，我们可知，最耗时的地方在于判断两个字符串中是否存在重复的字符。
一提到判断重复字符，脑海中马上浮现哈希大法。
又看到题目要保证字符串均为小写字母，也就说总共26个字母，我们需要26位，一个int足矣。
我们自定义，如果某字符出现，该bit置1，否则置0.
则比较两个字符串是否有重复字符，就是让这两个标志int 进行与操作，结果为0则表明没有重复字符。
好的，本题的难点已结束。code如下：
易知时间复杂度为O(n2)，空间复杂度为O(n)，其中n为所有字符串的个数。
**/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        if(words.empty())
            return 0;
        int result=0;
        vector<int> length;
        for(int i=0;i<words.size();i++)
            length.push_back(words[i].size());
        vector<int> hash_word(words.size(),0);
        for(int i=0;i<words.size();i++){
            int size=words[i].size();
            for(int j=0;j<size;j++){
                hash_word[i]|=(1<<words[i][j]-'a');
            }
        }
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words.size();j++){
                if((hash_word[i]&hash_word[j])==0){ //没有重复元素
                    if(length[i]*length[j]>result)
                        result=length[i]*length[j];
                }
            }
        }
        return result;
    }
};