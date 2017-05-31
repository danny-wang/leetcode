/**
409. Longest Palindrome
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
This is case sensitive, for example "Aa" is not considered a palindrome here.
Note:
Assume the length of given string will not exceed 1,010.
Example:
Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
思路：
hash table
First, characters are counted. Even occurring characters (v[i]%2 == 0) can always be used to build a palindrome. 
For every odd occurring character (v[i]%2 == 1), v[i]-1 characters can be used. Res is incremented if there is at least one character with odd occurrence number.
**/
class Solution {
public:
    int longestPalindrome(string s) {
        int hash[52];
        memset(hash,0,sizeof(hash));
        for(auto i : s){
            if(i<='Z')
                hash[i-'A']++;
            else
                hash[i-'a'+26]++;
        }
        int sig=true;
        int res=0;
        for(int i=0;i<52;i++){
            if(hash[i]==1){
                if(sig){
                    res++;
                    sig=false;
                }
            }
            if(hash[i]==0)
                continue;
            else{
                res+=(hash[i]>>1)*2;
                if( sig && hash[i]%2==1){
                    res++;
                    sig=false;
                }
            }
                
        }
        return res;
    }
};