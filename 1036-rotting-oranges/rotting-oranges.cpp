class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int time=-1;
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;//{row,col}
        //push all oranges into the queue who are already rotten at first
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
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
                        q.push({nr,nc});
                        vis[nr][nc]=1;
                    }
                }
            }
            time++;
        }
        //if any orange is never rotten then return -1
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]!=1){
                    return -1;
                }
            }
        }
        return max(0,time);
    }
};