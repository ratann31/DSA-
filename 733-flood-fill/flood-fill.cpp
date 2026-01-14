class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size();
        int n=image[0].size();
        /* begin with the starting pixel
        change its color to the color

        statrting pixel ka jo color tha waisa agr koi color ho to usko
        color color mei badal do
        */
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        int startingColor=image[sr][sc];
        image[sr][sc]=color;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;

            for(int dir=0;dir<4;dir++){
                int nr=row+dr[dir];
                int nc=col+dc[dir];

                if(nr>=0 && nr<m && nc>=0 && nc<n && image[nr][nc]==startingColor && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    image[nr][nc]=color;
                }
            }

        }
        return image;


        

    }
};