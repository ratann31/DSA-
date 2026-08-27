class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        //step-1:Transpose
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                if(i==j) continue;
                swap(matrix[j][i],matrix[i][j]);
            }
        }
        //step-2:Reverse each row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};