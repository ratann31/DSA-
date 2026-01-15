class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    bool isEdge(int i,int j,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();

        if(i==0 || i==m-1 || j==0 || j==n-1){
            return true;
        }
        return false;
    }

    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& board){
        int m=board.size();
        int n=board[0].size();
        vis[row][col]=1;
        
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];

            if(nr>=0 && nr<m && nc>=0 && nc<n && board[nr][nc]=='O' && !vis[nr][nc]){
                dfs(nr,nc,vis,board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isEdge(i,j,board) && board[i][j]=='O'){
                    dfs(i,j,vis,board);
                }
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        //for every unvisited cells make it 'X'
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j]){
                    board[i][j]='X';
                }
            }
        }
    }
};