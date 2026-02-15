class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mpp;
        for(int i=0;i<n;i++){
            if(words[i].size()<k)continue;
            string temp=words[i].substr(0,k);
            mpp[temp]++;
        }
        int ans=0;
        for(auto &it:mpp){
            if(it.second>=2){
                ans++;
            }
        }
        return ans;
    }
};