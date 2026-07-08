class Solution {
public:
    bool check(vector<int>&v,int target){
        int n=v.size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(v[mid]==target){
                return true;
            }else if(v[mid]>target){
                hi = mid-1;
            }else{
                lo = mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        bool found=false;
        for(int i=0;i<n;i++){
            bool temp = check(matrix[i],target);
            if(temp==true){
                found=true;
                return true;
            }
        }
        return false;
    }
};