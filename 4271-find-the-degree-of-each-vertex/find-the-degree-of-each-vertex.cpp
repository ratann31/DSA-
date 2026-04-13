class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int>ans(n);
        map<int,vector<int>>adj;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==1){
                    adj[i].push_back(j);
                    //adj[j].push_back(i);
                }
            }
        }
        //{vertex,{all edges to it}}
        for(auto &it:adj){  
            int x=it.first;
            ans[x]= ((int)it.second.size());
        }
        return ans;
    }
};