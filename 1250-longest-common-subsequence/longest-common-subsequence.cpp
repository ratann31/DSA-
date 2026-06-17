class Solution {
public:
    int solve(int idx1,int idx2,string &str1,string &str2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0)return 0;
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        if(str1[idx1]==str2[idx2]){
            return dp[idx1][idx2]=1+solve(idx1-1,idx2-1,str1,str2,dp);
        }
        return dp[idx1][idx2]=max(solve(idx1-1,idx2,str1,str2,dp),solve(idx1,idx2-1,str1,str2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();

        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,text1,text2,dp);
    }
};