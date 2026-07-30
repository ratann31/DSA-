class Solution {
public:
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>&dp){
        //base case
        if(i<0 && j<0)return 0;
        if(i<0 && j>=0)return j+1;
        if(i>=0 && j<0)return i+1;

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        //match
        if(s1[i]==s2[j]){
            return dp[i][j]=f(i-1,j-1,s1,s2,dp);
        }
        //not match
        return dp[i][j]= min({
                1+f(i-1,j,s1,s2,dp),
                1+f(i,j-1,s1,s2,dp),
                1+f(i-1,j-1,s1,s2,dp)
        });
        
    }
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size(); 
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n-1,m-1,word1,word2,dp);
    }
};