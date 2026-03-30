class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    bool inside(int i,int j,vector<vector<char>>&board){
        int row=board.size();
        int col=board[0].size();

        if(i==0 || i==row-1 || j==0 || j==col-1){
            return false;//edges  pe hai
        }
        return true;//andar hai
    }
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>&board){
        int m=board.size();
        int n=board[0].size();

        vis[row][col]=1;

        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];

           if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
            
            dfs(nr,nc,vis,board);
           }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();//no of rows
        int n=board[0].size();//no of col

        vector<vector<int>>vis(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!inside(i,j,board) && !vis[i][j] && board[i][j]=='O'){
                    dfs(i,j,vis,board);
                }
            }
        }
        //now all those cells which are not visited should be "X"

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};