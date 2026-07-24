class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();

        //step-1:Transpose
        for(int i=0;i<n;i++){
            for(int j=i+1;j<m;j++){
                if(i==j) continue;
                swap(matrix[j][i],matrix[i][j]);
            }
        }
          for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
              cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }
        //step-2:Reverse each row
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};