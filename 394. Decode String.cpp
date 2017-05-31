/**
394. Decode String 
Given an encoded string, return it's decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
Examples:
s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

思路：使用栈，类似于写一个计算器，计算有括号时的情况。这道题想了很久还没写出来。看了别人的代码才想清楚。都是一些细节问题。
**/
    class Solution {  
    public:  
        string decodeString(string s) {  
            stack<int> number;  //存数字  
            stack<string> str;  //存字符串  
            string ans;  
            int i=0;  
            while(i<s.length()){  
                if(s[i]<='9' && s[i]>='0'){  
                    int count=0;  
                    while(s[i]<='9' && s[i]>='0'){  
                        count = count*10+(s[i]-'0');  
                        i++;  
                    }//while  
                    number.push(count);  
                }else if(s[i]=='['){  
                    str.push(ans);  
                    ans="";  
                    i++;  
                }else if(s[i]==']'){  
                    string tmp=str.top();  
                    str.pop();  
                    int cnt=number.top();  
                    number.pop();  
                    for(int j=0; j<cnt; j++){  
                        tmp += ans;  
                    }//for  
                    ans=tmp;  
                    i++;  
                }else{  
                    ans+=s[i];  
                    i++;  
                }  
            }//while  
            return ans;  
              
        }  
    };  