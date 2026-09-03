class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int countPalindrome = 0;

        // Odd length
        for(int ax = 0; ax < n; ax++) {
            int l = ax;
            int r = ax;

            while(l >= 0 && r < n && s[l] == s[r]) {
                countPalindrome++;
                l--;
                r++;
            }
        }

        // Even length
        for(int ax = 0; ax < n - 1; ax++) {
            int l = ax;
            int r = ax + 1;

            while(l >= 0 && r < n && s[l] == s[r]) {
                countPalindrome++;
                l--;
                r++;
            }
        }

        return countPalindrome;
    }
};