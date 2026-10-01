class Solution {
public:
    int findLCS(string &s1,string &s2){
        int n1=s1.size();
        int n2=s2.size();

        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){

                int len = 0;
                if(s1[i-1]==s2[j-1]){
                    len = 1+dp[i-1][j-1];
                }else{
                    int len1=dp[i-1][j];
                    int len2=dp[i][j-1];

                    len = max(len1,len2);
                }

                dp[i][j]=len;
            }
        }

        return dp[n1][n2];
    }
    int longestPalindromeSubseq(string s) {
        string s1=s;
        string s2=s;
        reverse(s2.begin(),s2.end());

        return findLCS(s1,s2);
    }
};