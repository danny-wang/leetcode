/**
正则表达式匹配 

题目描述
请实现一个函数用来匹配包括'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。
 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

思路
如果模式串此时是'.'，那么只需要模式串与匹配串都往后移动一个位置即可
如果现在这位的字符能匹配且且模式串的下一位是'*'，我们则需要分情况讨论
1.匹配串往后移动1位，模式串跳过'*'
2.匹配串往后移动1位，模式串不动
3.匹配串不动，模式串跳过'*'
如果模式匹配字符的下一个字符不是‘*’，进行逐字符匹配。
对于 ‘.’ 的情况比较简单，’.’ 和一个字符匹配 match(str+1, pattern+1)
另外需要注意的是：空字符串”” 和 “.*” 是匹配的
**/
class Solution {
public:
    bool match(char* str, char* pattern)
    {
    	if(str==nullptr || pattern==nullptr)
            return false;
        return MatchCore(str, pattern);
    }
    bool MatchCore(char *str, char *pattern){
        if(*str=='\0' && *pattern=='\0')
            return true;
        if(*str!='\0' && *pattern=='\0')
            return false;
        if(*(pattern+1)=='*'){
            if(*str==*pattern || (*pattern=='.'&& *str!='\0'))
                return MatchCore(str+1,pattern) || MatchCore(str+1,pattern+2) || MatchCore(str, pattern+2);
            else  //ignore '*'
                return MatchCore(str, pattern+2);
        }
        if(*str==*pattern ||  (*pattern=='.'&& *str!='\0'))
            return MatchCore(str+1, pattern+1);
        else
            return false;
    }
};