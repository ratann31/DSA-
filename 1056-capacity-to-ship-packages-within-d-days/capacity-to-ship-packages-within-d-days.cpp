class Solution {
public:
    bool isPossible(int mid,vector<int>&weights,int days){
        int countDays=1;
        int currSum=0;
        for(int i=0;i<weights.size();i++){
            currSum+=weights[i];

            if(currSum>mid){
                countDays++;
                currSum=weights[i];
            }
        }

        return countDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();

        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);

        int ans=hi;

        while(lo<=hi){
            int mid = lo+(hi-lo)/2;

            if(isPossible(mid,weights,days)){
                ans=min(ans,mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return ans;

    }
};