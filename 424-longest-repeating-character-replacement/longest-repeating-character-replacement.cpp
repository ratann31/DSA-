class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();

        int l=0;
        int r=0;
        
        unordered_map<char,int>mpp;
        int ans=0;
        int maxFreq=0;
        while(r<n){
            mpp[s[r]]++;
            maxFreq=max(maxFreq,mpp[s[r]]);
            //invalid window condition
            while((r-l+1)-maxFreq >k){
                mpp[s[l]]--;
                l++;
            }
            int len=r-l+1;
            ans=max(ans,len);

            r++;
        }

        return ans;
    }
};