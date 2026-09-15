class Solution {
public:
    int f(int idx1,int idx2,string &s1,string &s2,vector<vector<int>>&dp){
        if(idx1<0 || idx2<0)return 0;
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        int len=0;

        if(s1[idx1]==s2[idx2]){
            len=1+f(idx1-1,idx2-1,s1,s2,dp);
        }else{
            int len1=f(idx1-1,idx2,s1,s2,dp);
            int len2=f(idx1,idx2-1,s1,s2,dp);

            len=max(len1,len2);
        }

        return dp[idx1][idx2] = len;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return f(n1-1,n2-1,text1,text2,dp);
    }
};