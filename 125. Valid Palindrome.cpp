/**125. Valid Palindrome
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.
For the purpose of this problem, we define empty string as valid palindrome.
思路：两个指针一个指向头，一个指向尾。判断是否相同，不同则返回false，相同一个往前走一步，另一个向后走一步  O（n）的时间复杂度
**/
class Solution {
public:
    bool isPalindrome(string s) {
        if(s=="")
            return true;
        auto l=s.begin();
        auto r=s.end()-1;
        while(l<r){
            if(!((*l>='a' && *l<='z')||(*l>='A' && *l<='Z')||(*l>='0' && *l<='9'))){
                l++;
                continue;
            }
            if(!((*r>='a' && *r<='z')||(*r>='A' && *r<='Z')||(*r>='0' && *r<='9'))){
                r--;
                continue;
            }
            char a;
            char b;
            if(*l>='0' && *l<='9'){
                a=*l;
            }
            else{
                a = (*l>='a' && *l<='z') ? *l-'a'+'A' : *l;
            }
            if(*r>='0' && *r<='9'){
                b=*r;
            }
            else{
                b = (*r>='a' && *r<='z') ? *r-'a'+'A' : *r;
            }
            if(a==b){
                l++;
                r--;
                continue;
            }
            else
                return false;
        }
        return true;
    }
};

//简单代码：
bool isPalindrome(string s) {
	int start=0, end=s.length()-1;
	while(start<end) {
		if (!isalnum(s[start])) start++;
		else if (!isalnum(s[end])) end--;
		else {
			if (tolower(s[start++])!=tolower(s[end--])) return false;
		}
	}
	return true;
}