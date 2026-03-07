class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;

       // vector<int>dp(n+1,0);
        // dp[0]=0;
        // dp[1]=1;
        int a=0;
        int b=1;
        int c;
        for(int i=2;i<=n;i++){
           c=a+b;
           a=b;
           b=c;
        }
        return b;
    }
};