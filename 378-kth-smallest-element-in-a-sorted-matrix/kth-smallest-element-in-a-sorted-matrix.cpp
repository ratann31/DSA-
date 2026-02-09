class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int R=matrix.size();
        int C=matrix[0].size();
        int ans;
        int lo=INT_MAX;
        int hi=INT_MIN;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                lo=min(lo,matrix[i][j]);
                hi=max(hi,matrix[i][j]);
            }
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            //find no of el less than or equal to mid(x)
            int x=0;
            for(int i=0;i<R;i++){
                auto it=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                x+=it;
            }
            if(x>=k){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
    }
};