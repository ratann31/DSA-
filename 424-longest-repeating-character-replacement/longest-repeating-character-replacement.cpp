class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        int maxLen = 0;
        int l = 0;
        int r = 0;
        vector<int> hash(26, 0);

        while (r < n) {
            hash[s[r] - 'A']++;

            int len = r - l + 1;
            int maxi = *max_element(hash.begin(), hash.end());

            while ((len - maxi) > k) {
                hash[s[l] - 'A']--;
                l++;

                len = r - l + 1;
                maxi = *max_element(hash.begin(), hash.end());
            }

            maxLen = max(maxLen, len);
            r++;
        }

        return maxLen;
    }
};