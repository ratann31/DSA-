class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        
        int maxPoints=0;
        for(int i=0;i<k;i++){
            maxPoints+=cardPoints[i];
        }
        int l=k-1;
        int r=n-1;
        int ans=maxPoints;
        while(k-- && l<r){
            maxPoints-=cardPoints[l];
            maxPoints+=cardPoints[r];

            ans=max(maxPoints,ans);
            l--;
            r--;
        }

        return ans;
    }
};