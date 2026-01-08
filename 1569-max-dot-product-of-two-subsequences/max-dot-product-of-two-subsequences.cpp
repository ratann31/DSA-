class Solution {
public:
    int f(int i,int j,vector<int>&nums1,vector<int>&nums2,vector<vector<int>>&dp){
        if(i==nums1.size() || j==nums2.size()){
            return (-1)*1e9;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int val=nums1[i]*nums2[j];
        int take_i_j=nums1[i]*nums2[j]+f(i+1,j+1,nums1,nums2,dp);
        int take_i=f(i,j+1,nums1,nums2,dp);
        int take_j=f(i+1,j,nums1,nums2,dp);

        return dp[i][j]= max({val,take_i_j,take_i,take_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(0,0,nums1,nums2,dp);
    }
};