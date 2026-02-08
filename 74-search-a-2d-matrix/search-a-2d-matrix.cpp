class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int R=matrix.size();
        int C=matrix[0].size();
        int lo=0,hi=R*C-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            int row_=mid/C;
            int col_=mid%C;

            if(matrix[row_][col_]==target){
                return true;
            }
            else if(matrix[row_][col_]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return false;
    }
};