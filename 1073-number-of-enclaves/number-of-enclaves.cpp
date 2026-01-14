class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    bool isEnd(int i,int j,vector<vector<int>>&grid){
        int m=grid.size();
        int n=grid[0].size();

        if(i==0 || i==m-1 || j==0 || j==n-1){
            return true;
        }
        return false;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
       
        queue<pair<int,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isEnd(i,j,grid) && grid[i][j]==1){
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
                for(int i=0;i<4;i++){
                    int nr=row+dr[i];
                    int nc=col+dc[i];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }

            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //now count all those 1s which are untouched to the end of the grid
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;

    }
};