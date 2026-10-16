class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int total = row*col;
        int lo=0,hi=total-1;

        while(lo<=hi){
            int mid = (lo+hi)/2;

            int r=mid/col;
            int c=mid%col;

            if(matrix[r][c]==target){
                return true;
            }else if(matrix[r][c]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }

        return false;
    }
};