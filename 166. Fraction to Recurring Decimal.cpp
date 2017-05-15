/**
166. Fraction to Recurring Decimal
Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
If the fractional part is repeating, enclose the repeating part in parentheses.
For example,
  ● Given numerator = 1, denominator = 2, return "0.5".
  ● Given numerator = 2, denominator = 1, return "2".
  ● Given numerator = 2, denominator = 3, return "0.(6)".
分析如下：
对于可以整除的，和对于不可以整除但是算出来的小数不是循环小数的，都可以直接计算结果转化为字符串。
比较麻烦的是循环节的小数。为了找到循环节，可以用hashtable保存每一步余数，如果当前余数和之前某个余数相同，则重复之间的这段发生循环。
余数*10/被除数  就是商中的一位
注意点：
1、正负号
2、分子为0
3、可能出现INT_MIN/-1的越界情况，因此第一步现将int转为long long int
**/
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(denominator==0)
            return 0;
        if(numerator==0)
            return "0";
        map<long long,long long> m;
        bool sig=true; //乘为正数
        if((numerator<0)^(denominator<0))
            sig=false;
        vector<long long> result;
        long long a=numerator;
        long long b=denominator;
        a=abs(a);
        b=abs(b);
        long long shang=a/b;
        long long yushu=a%b;
        int i=0;
        result.push_back(shang);
        m.insert(make_pair(yushu,i));
        i++;
        int loc=-1;
        while(yushu != 0){
            shang=(yushu*10/b);
            yushu=yushu*10%b;
            //cout<<shang<<"    "<<yushu<<endl;
            if(m.find(yushu)!=m.end()){
                result.push_back(shang);
                loc=m[yushu];
                break;
            }
            else{
                m.insert(make_pair(yushu,i));
                result.push_back(shang);
                i++;
            }
        }
        stringstream ss;
        if(!sig)
            ss<<"-";
        ss<<result[0];
        if(loc==-1){
            if(result.size()>1)
                ss<<".";
            for(int i=1;i<result.size();i++)
                ss<<result[i];
        }
        else{
            if(result.size()>1)
                ss<<".";
            for(int i=1;i<=loc;i++)
                ss<<result[i];
            ss<<"(";
            for(int i=loc+1;i<result.size();i++)
                ss<<result[i];
            ss<<")";
        }
        string s=ss.str();
        return s;
    }
};