class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    void bfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis,int m,int n){
         queue<pair<int,int>>q;//{row,col}
         q.push({row,col});
         vis[row][col]=1;
         while(!q.empty()){
            auto it=q.front();
            int currRow=it.first;
            int currCol=it.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nRow=dr[i]+currRow;
                int nCol=dc[i]+currCol;

                if(nRow<m && nCol<n && nRow>=0 && nCol>=0 && !vis[nRow][nCol] && grid[nRow][nCol]=='1'){
                    q.push({nRow,nCol});
                    vis[nRow][nCol]=1;
                }
            }
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        int islands=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
       
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    islands++;
                    bfs(i,j,grid,vis,m,n);
                }
            }
        }

        return islands;
    }
};