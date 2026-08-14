class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        if(s.size()<=10){
            return {};
        }
        string temp = s.substr(0,10);
        vector<string>ans;
        unordered_map<string,int>mpp;
        set<string>st;
        mpp[temp]++;
        int l=0,r=10;
        while(r<n){
            temp+=s[r];
            temp.erase(0,1);
            l++;
            mpp[temp]++;
            if(mpp[temp]==2){
                ans.push_back(temp);
            }
            r++;
        }
        // vector<string>ans;
        // for(auto &it:st){
        //     ans.push_back(it);
        // }

        return ans;

    }
};