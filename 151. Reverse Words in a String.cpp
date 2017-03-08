/**
Given an input string, reverse the string word by word.
For example,
Given s = "the sky is blue",
return "blue is sky the".
Update (2015-02-12):
For C programmers: Try to solve it in-place in O(1) space
思路：如果利用C++的stringstream类将字符串以空格分开，将会使得题目变得极其简单，但是这并不是这题的目的，这题考察的就是操作数组的能力，也就是不能使用额外的空间。
方法二：经过两步解决，首先，反转整个字符串，然后从前向后遍历，每经过一个单词，反转该单词一次。 
当然在过程中，必须合理的处理多余空格问题。
**/
//利用stringstream的代码：
class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string temp;
        s.clear();
        while(ss>>temp){
            s=temp+" "+s;
        }
        s=s.substr(0,s.size()-1);     
    }
};
//两步反转的代码：
class Solution {
public:
    void reverseWords(string &s) {
        if(s=="")
            return;
        std::reverse(s.begin(),s.end());
        string temp=s;
        s.clear();
        int i=0;
        for(i=0;i<temp.size();i++){//找到第一个非空的字符
            if(temp[i]==' ')
                continue;
            else
                break;
        }
        bool is_first=true;
        for(int j=i; j<temp.size();j++ ){
            if(temp[j]!=' '){
                continue;
            }
            else if(temp[j]==' '&&temp[j-1]==' ')
                i=j+1;
            else{
                if(is_first){
                    cout<<i<<" "<<j-i<<"  "<<temp.substr(i,j-i)<<endl;
                    string reverse_substr=temp.substr(i,j-i);
                    std::reverse(reverse_substr.begin(),reverse_substr.end());
                    s=reverse_substr;
                    is_first=false;
                    i=j+1;
                }
                else{
                    string reverse_substr=temp.substr(i,j-i);
                    std::reverse(reverse_substr.begin(),reverse_substr.end());
                    s=s+" "+reverse_substr;
                    i=j+1;
                }
            }
        }
        if(temp[temp.size()-1]!=' '){
            if(is_first){
                string reverse_substr=temp.substr(i,temp.size()-1-i+1);
                std::reverse(reverse_substr.begin(),reverse_substr.end());
                s=reverse_substr;
                }
            else{
                string reverse_substr=temp.substr(i,temp.size()-1-i+1);
                std::reverse(reverse_substr.begin(),reverse_substr.end());
                s=s+" "+reverse_substr;
                }
        }
        return;
    }
};