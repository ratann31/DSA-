class Solution {
public:
    bool peak(int r, int c, int maxi, vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    // Check top neighbor (if exists)
    if (r > 0 && maxi <= mat[r-1][c]) return false;
    // Check bottom neighbor (if exists)
    if (r < n-1 && maxi <= mat[r+1][c]) return false;
    // Check left neighbor (if exists)
    if (c > 0 && maxi <= mat[r][c-1]) return false;
    // Check right neighbor (if exists)
    if (c < m-1 && maxi <= mat[r][c+1]) return false;
    
    return true;
}
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int R=mat.size();
        int C=mat[0].size();
        int lo=0,hi=C-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            //now to to col no mid and find the largest no 
            //in this column
            int maxi=INT_MIN;
            int mxRow;
            int mxCol=mid;
            for(int i=0;i<R;i++){
                if(mat[i][mid]>maxi){
                    maxi=mat[i][mid];
                    mxRow=i;
                }
            }
            //check if maxi can be peak el or not 
            if(peak(mxRow,mxCol,maxi,mat)){
                return {mxRow,mxCol};
            }else if(mxCol>0 && maxi<mat[mxRow][mxCol-1]){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return {-1,-1};
    }
};