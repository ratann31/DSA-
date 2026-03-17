class Solution {
public:
    int findTime(vector<int>&weights,int mid){
        int n=weights.size();
        int days=1;
        int x=mid;
        for(int i=0;i<n;i++){
            if(x<weights[i]){
                days++;
                x=mid;
            }
            x-=weights[i];
            
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int lo=*max_element(weights.begin(),weights.end());
        int hi=accumulate(weights.begin(),weights.end(),0);
        int ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int timeTaken=findTime(weights,mid);
            if(timeTaken>days){
                lo=mid+1;
            }else{
                hi=mid-1;
                ans=mid;
            }
        }
        return ans;

    }
};