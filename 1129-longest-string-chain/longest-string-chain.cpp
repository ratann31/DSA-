class Solution {
public:
    static bool cmp(const string &s1,const string& s2){
        return s1.size() < s2.size();
    }
    bool check(string &s1,string &s2){
        if(s1.size() != s2.size()+1) return false;
        int first = 0;
        int second = 0;

        while(first < s1.size()){ //kyu ki s2 chhota wala string hai
            if(second < s2.size() && s1[first]==s2[second]){
                first++;
                second++;
            }else{
                first++; 
            }
            
        }

        if(first==s1.size() && second==s2.size()) return true;
        return false;
           
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp); //sort according to the length
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j])){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};