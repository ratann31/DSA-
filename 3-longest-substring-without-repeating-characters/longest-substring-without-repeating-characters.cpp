class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        unordered_map<char,int>mpp;//{char,count}
        int maxLen=0;

        int l=0;
        int r=0;
        while(r<n){
            mpp[s[r]]++;

            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                l++;
            }

            int len=r-l+1;
            maxLen=max(maxLen,len);
            r++;
        }

        return maxLen;
    }
};