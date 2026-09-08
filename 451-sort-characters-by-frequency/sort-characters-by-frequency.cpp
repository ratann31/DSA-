class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto &it:mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();

            char curr=it.second;
            int f=it.first;

            for(int i=0;i<f;i++){
                ans+=curr;
            }
        }

        return ans;
    }
};