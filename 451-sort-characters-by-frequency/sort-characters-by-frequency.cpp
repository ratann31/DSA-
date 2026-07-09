class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        priority_queue<pair<int,int>>pq;
        unordered_map<char,int>mpp;//{char,freq}
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }
        for(auto &it:mpp){
            char ch=it.first;
            int freq=it.second;

            pq.push({freq,ch});
        }
        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            char ch=it.second;
            int f=it.first;

            while(f>0){
                ans+=ch;
                f--;
            }
        }
        return ans;
    }
};