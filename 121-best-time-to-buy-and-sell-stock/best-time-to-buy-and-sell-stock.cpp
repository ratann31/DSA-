class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX;
        int ans=0;

        for(int i=0;i<prices.size();i++){
            //best buying price till now 
            mn=min(mn,prices[i]);

            //sell today
            int profit=prices[i]-mn;
            ans=max(ans,profit);
        }
        return ans;
    }
};