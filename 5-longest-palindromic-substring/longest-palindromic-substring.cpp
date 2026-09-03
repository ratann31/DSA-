class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";

        // Odd length palindromes
        for(int ax = 0; ax < n; ax++) {
            int l = ax;
            int r = ax;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > res.size()) {
                    res = s.substr(l, r - l + 1);
                }

                l--;
                r++;
            }
        }

        // Even length palindromes
        for(int ax = 0; ax < n - 1; ax++) {
            int l = ax;
            int r = ax + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                if(r - l + 1 > res.size()) {
                    res = s.substr(l, r - l + 1);
                }

                l--;
                r++;
            }
        }

        return res;
    }
};