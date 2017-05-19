/**
372. Super Pow 
Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.
Example1:
a = 2
b = [3]

Result: 8

Example2:
a = 2
b = [1,0]

Result: 1024

思路: 需要用到的数学知识
1. a^b % 1337 = (a%1337)^b % 1337
2. xy % 1337 = ((x%1337) * (y%1337)) % 1337, 其中xy是一个数字如:45, 98等等
首先求基数：
eg: 对于a=2,b=[1,2,1].  就是求2^121%1337,也就是2^100 * 2^20 * 2^1%1337.等价与2^100 *（2^10）^2 * 2^1%1337.
所以首先求出   2^100	2^10	2^1，存储在数组base中
然后按照b对应的位去求结果。
注意：算指数的时候有可能会溢出，所以一位一位乘，每次乘完都要取余，防止溢出。
时间复杂度为O(n)
**/
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty())
            return 1;
        int size=b.size();
        a=a%1337;
        vector<int> base(size,0);
        base[size-1]=a;
        if(size>1){
            int count=0;
            int temp=1;
            while(count<10){
                temp=temp*a%1337;
                count++;
            }
            base[size-2]=temp;
        }
        for(int i=size-3;i>=0;i--){
            int count=0;
            int temp=1;
            while(count<10){
                temp=temp*base[i+1]%1337;
                count++;
            }
            base[i]=temp;
        }
        int res=1;
        //for(auto i: base)
        //    cout<<i<<endl;
        for(int i=size-1;i>=0;i--){
            //res*=(int)pow(base[i],b[i])%1337;
            int count=0;
            int temp=1;
            while(count<b[i]){
                temp=temp*base[i]%1337;
                count++;
            }
            res=res*temp%1337;
        }
        return res;
        
    }
};

