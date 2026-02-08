class Solution {
public:
    bool check(vector<int>&v,int t){
        int n=v.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==t){
                return true;
            }else if(v[mid]>t){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R=matrix.size();
        int C=matrix[0].size();
        for(int i=0;i<R;i++){
            if(check(matrix[i],target)){
                return true;
            }
        }
        return false;
    }
};