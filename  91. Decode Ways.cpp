 /**
 91. Decode Ways

 A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26

Given an encoded message containing digits, determine the total number of ways to decode it.
For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.
思路：
这道题的要求是判断一个只包含数字的字符串可能有几种编码方式。
动态规划，令dp[i]表示字符串的前i个字符的可能的编码方式的数量。那么递推公式如下：
  ● 如果当前数字为0，则前面数字必为1或者2，否则无法进行编码转换，此时的数字0只能和前面的1或者2连在一起进行编码，因此dp[i] = dp[i-2]；
  ● 如果前面数字为1或者（前面数字为2且当前数字在1~6之间），说明都可以进行2种编码（分开或者和在一起），因此dp[i] = dp[i-1] + dp[i-2]；
  ● 其他情况，当前数字必须单独进行编码转换，因此dp[i] = dp[i-1]。
可以注意到，递推公式中，只是利用到了前面2个结果，因此无需申请dp数组保存前面状态，只需要2个变量a1和a2保存前面2个状态即可，这样空间复杂度降低为O(1)。
时间复杂度：O(n)
空间复杂度：O(1)
**/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0')
            return 0;
        if(s.size()==1){    //长度为1的时候
            if('0'<s[0] && s[0]<='9')
                return 1;
            else
                return 0;
        }
        int pre_2=1;
        int pre_1=0;
        if(s.size()>=2){  //长度大于等于2的时候
            if('0'<s[0] && s[0]<='9' &&'0'<=s[1] && s[1]<='9'){
                int a=s[0]-'0';
                int b=s[1]-'0';
                int val=a*10+b;
                if(s[1]=='0' ){
                    if(s[0]!='1' && s[0]!='2')
                        return 0;
                    else 
                        pre_1=1;
                }
                else if(val>=10 &&val<=26){
                    pre_1=2;
                }
                else
                    pre_1=1;
            }
            else
                return 0;
        }
        int length=s.size();
        for(int i=2;i<length;i++){
            if('0'<=s[i] && s[i]<='9'){
                int a=s[i-1]-'0';
                int b=s[i]-'0';
                int val=a*10+b;
                if(s[i]=='0'  ){
                    if( s[i-1]!='1' && s[i-1]!='2' )
                        return 0;
                }
                if(s[i]=='0'){
                    int temp=pre_1;
                    pre_1=pre_2;
                    pre_2=temp;
                }
                
                else if(val>=10 &&val<=26){
                    int temp=pre_1;
                    pre_1+=pre_2;
                    pre_2=temp;
                }
                else{
                    pre_2=pre_1;
                }
            }
            else
                return 0;
        }
        return pre_1;
    }
};