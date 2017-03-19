class Solution {
public:
    int Fibonacci(int n) {
        if(n<=0)
            return 0;
        if(n==1 || n==2)
            return 1;
		    int a=1;
        int b=1;
        for(int i=3;i<=n;i++){
            int old_a=a;
            a=b;
            b=old_a+b;
        }
        return b;
    }
};
