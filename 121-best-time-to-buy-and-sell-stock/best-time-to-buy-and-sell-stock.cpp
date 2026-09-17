class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int maxProfit=0;
        int currPrice = prices[0];

        for(int i=1;i<n;i++){
            //if other stocks are less than currPrice then currPrice = prices[i]
            if(prices[i]<=currPrice){
                currPrice = prices[i];
            }else{
                //sell current stock
                int profit=prices[i]-currPrice;
                maxProfit=max(maxProfit,profit);
            }
        }

        return maxProfit;
    }
};