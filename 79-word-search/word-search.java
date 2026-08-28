class Solution {
    boolean dfs(char[][] board,String word,int row,int col,int idx){
        if(idx==word.length()){
            return true;
        }

        if(row<0 || row>=board.length || col<0 || col>=board[0].length){
            return false;
        }

        if(board[row][col]!=word.charAt(idx))return false;

        char temp=board[row][col];
        board[row][col]='#';

        boolean found = 
            dfs(board,word,row-1,col,idx+1)||
            dfs(board,word,row+1,col,idx+1)||
            dfs(board,word,row,col-1,idx+1)||
            dfs(board,word,row,col+1,idx+1);
        
        board[row][col]=temp;

        return found;
    }
    public boolean exist(char[][] board, String word) {
        int n=board.length;
        int m=board[0].length;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]==word.charAt(0)){
                    if(dfs(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
}