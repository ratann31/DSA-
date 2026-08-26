class Solution {
public:
    vector<int>findpse(vector<int>&nums){
        int n=nums.size();
        vector<int>pse(nums.size(),0);
        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }else{
                pse[i]=st.top();
            }
            st.push(i);
        }

        return pse;
    }
    vector<int>findnse(vector<int>&nums){
        int n=nums.size();
        vector<int>nse(nums.size(),0);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=n;
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }

        return nse;

    }
    int maximumScore(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>pse=findpse(nums);
        vector<int>nse=findnse(nums);

        int ans=0;

        for(int i=0;i<n;i++){
            int l=pse[i]+1;
            int r=nse[i]-1;

            int score=nums[i]*(r-l+1);
            if(l<=k && k<=r){
                ans=max(ans,score);
            }
        }
        
        return ans;
    }
};