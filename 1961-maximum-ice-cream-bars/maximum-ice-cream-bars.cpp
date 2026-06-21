class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int remaining_money=coins;
        int ans=0;
        for(int i=0;i<costs.size();i++){
            if(costs[i]<=remaining_money){
                ans++;
                remaining_money-=costs[i];
            }else{
                break;
            }
        }
        return ans;
    }
};