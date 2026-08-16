class Solution {
public:
    string minWindow(string s, string t) {

        // If t is bigger than s, answer is impossible
        if (t.size() > s.size())
            return "";

        // Store how many times each character is needed
        unordered_map<char, int> mp;

        for (char ch : t) {
            mp[ch]++;
        }

        int left = 0;

        // count = how many required characters
        // are currently present in our window
        int count = 0;

        // Store answer
        int start = 0;
        int minLen = INT_MAX;

        // right expands the window
        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];

            // If this character is needed
            if (mp[ch] > 0) {
                count++;
            }

            // We got this character, so decrease its requirement
            // It can become negative if it is an extra character
            mp[ch]--;

            // When all characters of t are present
            while (count == t.size()) {

                // Check if current window is smaller
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }

                // Remove the left character
                char remove = s[left];

                // We are removing this character,
                // so add its requirement back
                mp[remove]++;

                // If mp[remove] becomes positive,
                // it means we removed a required character
                if (mp[remove] > 0) {
                    count--;
                }

                // Move left forward
                left++;
            }
        }

        // No valid window found
        if (minLen == INT_MAX)
            return "";

        // Return the minimum window
        return s.substr(start, minLen);
    }
};