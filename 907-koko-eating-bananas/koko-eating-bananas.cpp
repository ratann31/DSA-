class Solution {
public:
    bool isValid(vector<int>&piles,int mid,int h){
        long long  time=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%mid==0){
                time+=(piles[i]/mid);
            }else{
                time+=(piles[i]/mid);
                time+=1;
            }
        }
        return time<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int lo=1;
        int hi=*max_element(piles.begin(),piles.end());

        int ans=-1;

        while(lo<=hi){
            int mid = (lo+hi)>>1;
            if(isValid(piles,mid,h)){
                hi=mid-1;
                ans=mid;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};