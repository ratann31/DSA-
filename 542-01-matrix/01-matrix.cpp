class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        queue<pair<int,int>>q;//{row,col}
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dist(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto it=q.front();
                q.pop();
                int row=it.first;
                int col=it.second;

                for(int dir=0;dir<4;dir++){
                    int nr=row+dr[dir];
                    int nc=col+dc[dir];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && mat[nr][nc]==1 && !vis[nr][nc]){
                        vis[nr][nc]=1;
                        dist[nr][nc]=dist[row][col]+1;
                        q.push({nr,nc});

                    }
                }
            }
        }
        return dist;
    }
};