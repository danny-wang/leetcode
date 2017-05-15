/**
306. Additive Number
Additive number is a string whose digits can form additive sequence.
A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
Follow up:
How would you handle overflow for very large input integers?

思路: 一个基本的思想就是确定了第一个和第二个数之后, 以后的数就是验证了, 
所以只要枚举第一和第二个数, 然后不断验证下面的字符串子串是否是前两个数的和即可.
 因为数字可能超出整数的范围, 因此在验证一个数是否是另外两个和的时候, 可以用字符串相加来模拟整数相加. 
 另外需要注意的是'0'字符, 如果他在子串的首位, 那么他只能以"0"的形式存在, 并且"0"只可能作为第一个数或者第二个数.
**/
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int size=((num.size()-1)>>1);
        for(int i=1;i<=size;i++){
            for(int j=i+1;j<num.size();j++){
                string a=num.substr(0,i);
                cout<<a<<endl;
                string b=num.substr(i,j-i);
                cout<<b<<endl;
                if((a.size()>1 &&a[0]=='0')||(b.size()>1 && b[0]=='0'))
                    continue;
                long long a_val=atoll(a.c_str());
                long long b_val=atoll(b.c_str());
                long long sum=a_val+b_val;
                string c=a+b+(to_string(sum));
                cout<<c<<endl;
                while(c==num.substr(0,c.size())){
                    if(c==num)
                        return true;
                    a_val=b_val;
                    b_val=sum;
                    sum=a_val+b_val;
                    c+=(to_string(sum));
                }
                if(c==num)
                    return true;
            }
        }
        return false;
    }
};