class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        int l=0,r=0;
        int maxLen=0;
        while(r<n){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                if(mpp[s[l]]==1){
                    mpp.erase(s[l]);
                }else{
                    mpp[s[l]]--;
                }
                l++;
            }
            int len=r-l+1;
            maxLen =  max(maxLen,len);
            r++;
        }

        return maxLen;

    }
};