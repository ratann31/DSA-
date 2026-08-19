class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int sz = reservedSeats.size();

        unordered_map<int, vector<int>> mpp;

        for (int i = 0; i < sz; i++) {
            int row = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            mpp[row].push_back(seat);
        }

        int ans = 0;

        for (auto &it : mpp) {
            auto v = it.second;

            unordered_map<int, int> mpp1;

            for (int i = 0; i < v.size(); i++) {
                mpp1[v[i]]++;
            }

            // Check [2,3,4,5]
            bool left = true;
            for (int i = 2; i <= 5; i++) {
                if (mpp1.find(i) != mpp1.end()) {
                    left = false;
                    break;
                }
            }

            // Check [6,7,8,9]
            bool right = true;
            for (int i = 6; i <= 9; i++) {
                if (mpp1.find(i) != mpp1.end()) {
                    right = false;
                    break;
                }
            }

            if (left && right) {
                // Both groups can fit
                ans += 2;
            }
            else if (left || right) {
                // One side can fit
                ans += 1;
            }
            else {
                // Check middle group [4,5,6,7]
                bool middle = true;

                for (int i = 4; i <= 7; i++) {
                    if (mpp1.find(i) != mpp1.end()) {
                        middle = false;
                        break;
                    }
                }

                if (middle) {
                    ans += 1;
                }
            }
        }

        // Rows which have no reserved seats
        int remaining = n - mpp.size();

        // Every completely empty row can fit 2 families
        ans += 2 * remaining;

        return ans;
    }
};