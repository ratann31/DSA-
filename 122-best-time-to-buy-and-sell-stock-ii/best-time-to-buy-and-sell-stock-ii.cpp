class Solution {
public:
    int f(int idx,int canBuy,vector<int>&prices,vector<vector<int>>&dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][canBuy]!=-1){
            return dp[idx][canBuy];
        }
        //buy
        int profit = 0;
        if(canBuy==1){
            //buy karlo
            int buyStock = -prices[idx] + f(idx+1,0,prices,dp);
            int skip = f(idx+1,1,prices,dp);

            profit=max(buyStock,skip);

        }else{ //sell
            int sellStock = prices[idx] + f(idx+1,1,prices,dp);
            int hold = f(idx+1,0,prices,dp);

            profit=max(sellStock,hold);
        }
        return dp[idx][canBuy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};