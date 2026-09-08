class Solution {
public:

    struct compare {
        bool operator()(pair<int,string> a, pair<int,string> b) {

            if(a.first == b.first) {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {

        int n = words.size();

        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            compare
        > pq;

        unordered_map<string,int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[words[i]]++;
        }

        for(auto &it : mpp) {

            int freq = it.second;
            string s = it.first;

            if(pq.size() < k) {
                pq.push({freq, s});
            }
            else {

                if(freq > pq.top().first ||
                  (freq == pq.top().first && s < pq.top().second)) {

                    pq.pop();
                    pq.push({freq, s});
                }
            }
        }

        vector<string> ans;

        while(!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            ans.push_back(it.second);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};