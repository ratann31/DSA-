class Solution {
public:
    int f(int idx,int buyOrSell,vector<int>&prices,vector<vector<int>>&dp){
        //base case
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][buyOrSell]!=-1){
            return dp[idx][buyOrSell];
        }
        int profit=0;
        if(buyOrSell==0){
            int buy=-prices[idx]+f(idx+1,1,prices,dp);
            int notBuy=f(idx+1,0,prices,dp);

             profit=max(buy,notBuy);
        }else{
            int sell = prices[idx] + f(idx+2,0,prices,dp);
            int notSell = f(idx+1,1,prices,dp);

             profit=max(sell,notSell);
        }

        return dp[idx][buyOrSell] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0,0,prices,dp);
    }
};