class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n,vector<int>(n,0));

        int left=0,right=n-1,top=0,bottom=n-1;
        int x=1;
        while(left<=right && top<=bottom){
            for(int j=left;j<=right;j++){
                ans[top][j]=x;
                x+=1;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans[i][right]=x;
                x+=1;
            }
            right--;

            if(top<=bottom){
                for(int j=right;j>=left;j--){
                    ans[bottom][j]=x;
                    x+=1;
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=x;
                    x+=1;
                }
            }
            left++;
        }

        return ans;
        
    }
};