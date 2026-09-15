class Solution {
public:
    int f(int idx,int canBuy,int limit,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(idx==prices.size())return 0;
        if(limit==0)return 0;

        if(dp[idx][canBuy][limit]!=-1){
            return dp[idx][canBuy][limit];
        }
        int profit=0;

        if(canBuy==1){
            int buy=-prices[idx]+f(idx+1,0,limit,prices,dp);
            int notBuy=f(idx+1,1,limit,prices,dp);

            profit=max(buy,notBuy);
        }else{
            int sell=prices[idx]+f(idx+1,1,limit-1,prices,dp);
            int notSell=f(idx+1,0,limit,prices,dp);
            
            profit=max(sell,notSell);
        }

        return dp[idx][canBuy][limit]=profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,prices,dp);
    }
};