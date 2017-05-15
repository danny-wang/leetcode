/**
313. Super Ugly Number
Write a program to find the nth super ugly number.
Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.
Note:
(1) 1 is a super ugly number for any given primes.313
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.
思路：类似于Ugly Number II, 由3个序列合并改为由primes.size()个序列进行合并。
**/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size=primes.size();
        vector<int> origin_data={1};
        origin_data.reserve(n);
        vector<int> index(size,0);
        int count=1;
        int result=1;
        for(int i=1;i<n;i++){
            int next_num=INT_MAX;
            for(int i=0;i<primes.size();i++){
                int temp=primes[i]*origin_data[index[i]];
                if(temp<next_num)
                    next_num=temp;
            }
            origin_data[i]=next_num;
            //cout<<next_num<<endl;
            count++;
            if(count==n)
                return next_num;
            for(int i=0;i<primes.size();i++){
                if(origin_data[index[i]]*primes[i]==next_num)
                    index[i]++;
            }
        }
        return result;
    }
};