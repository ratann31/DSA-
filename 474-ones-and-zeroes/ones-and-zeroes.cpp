class Solution {
public:
    int solve(int idx,vector<pair<int,int>>&cnt,int m,int n,vector<string>&strs,vector<vector<vector<int>>>&dp){
        if(idx<0){
            return 0;
        }
        int zeros=cnt[idx].first;
        int ones=cnt[idx].second;
        if(dp[idx][m][n]!=-1){
            return dp[idx][m][n];
        }
        int skip=solve(idx-1,cnt,m,n,strs,dp);
        int pick=0;
        if(zeros<=m && ones<=n){
            pick=1+solve(idx-1,cnt,m-zeros,n-ones,strs,dp);
        }
        return dp[idx][m][n]=max(pick,skip);
    }   
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        vector<vector<vector<int>>>dp(sz,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        vector<pair<int,int>>cnt;
        for(int i=0;i<sz;i++){
            string temp=strs[i];
            int z=0,o=0;
            for(int j=0;j<temp.size();j++){
                if(strs[i][j]=='0'){
                    z++;
                }else{
                    o++;
                }
            }
            cnt.push_back({z,o});
        }
        return solve(sz-1,cnt,m,n,strs,dp);
    }
};