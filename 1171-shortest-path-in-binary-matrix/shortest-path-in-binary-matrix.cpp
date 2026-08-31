class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]!=0){
            return -1;
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        int dist=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                int currRow=it.first;
                int currCol=it.second;
                q.pop();

                if(currRow==n-1 && currCol==m-1){
                    return dist;
                }
                for(int dx=-1;dx<=1;dx++){
                    for(int dy=-1;dy<=1;dy++){
                        int adjRow=currRow+dx;
                        int adjCol=currCol+dy;

                        if(adjRow>=0 && adjRow<n && adjCol>=0 && adjCol<m && !vis[adjRow][adjCol] && grid[adjRow][adjCol]==0){
                            vis[adjRow][adjCol]=1;
                            q.push({adjRow,adjCol});
                        }
                    }
                }
            }
            dist++;
        }
        
        return -1;
    }
};