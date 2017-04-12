/** 93. Restore IP Addresses 
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example:
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
思路：IP地址的格式：
1）一定是4个字段，每个字段最多三个字符的数字；
2）子字段可以为0，但不能为00，01，001；
3）子字段的转成int的范围是0到255。 可以使用DFS的方法，依次取1，2，3长度的子串，判断其为合法的IP地址子字段后，取后面的真个字符串递归判断，通过count从0增加到3来判断是否完成4个子段的判断，将结果加入最终的result中去。
**/
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.empty() ||s.size()<4 ||s.size()>12)
            return {};
        vector<string> res;
        string temp;
        helper(s,0,temp,res);
        return res;
    }
    void helper(string s, int count, string cur, vector<string> &res){
        if(count==3){
            if(IsValid(s)){
                string temp=cur+s;
                cout<<temp<<endl;
                res.push_back(temp);
                return;
            }
            else
                return;
        }
        for(int i=1;i<=3 && i<s.size();i++){
            if(IsValid(s.substr(0,i)))
                helper(s.substr(i),count+1,cur+s.substr(0,i)+".", res);
        }
    }
    bool IsValid(string s){
        if(s[0]=='0'){
            return s.size()==1;
        }
        int size=atoi(s.c_str());
        if(size<256)
            return true;
        else
            return false;
    }
};