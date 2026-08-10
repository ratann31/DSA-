class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        unordered_map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.size();i++){
            char ch=t[i];
            if(mpp.find(ch)==mpp.end()){
                return false;
            }
            else{
                if(mpp[ch]==1){
                    mpp.erase(ch);
                }else{
                    mpp[ch]-=1;
                }
            }
        }

        return true;
    }
};