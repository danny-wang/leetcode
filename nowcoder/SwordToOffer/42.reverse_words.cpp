/**
翻转单词顺序列 

题目描述
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
**/
class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size()==0)
            return str;
        string temp=str;
        reverse(temp.begin(),temp.end());
        int left=0;
        int right=0 ;
        while(right<temp.size()){
            if(temp[right]==' '){  //遇到空格，翻转从left到right的单词
                reverse(temp.begin()+left,temp.begin()+right);
                left=right+1;
                right++;
            }
            else if(right==(temp.size()-1)){  //到string的尾部，翻转从left到尾
                reverse(temp.begin()+left,temp.end());
                right++;
            }
            else
                right++;
        }
        return temp;
    }
};