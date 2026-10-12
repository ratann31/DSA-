class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        int ans=0;
        int l=0,r=0;

        unordered_map<char,int>mpp;

        while(r<n){
            mpp[s[r]]++;

            while(mpp[s[r]]>1){
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