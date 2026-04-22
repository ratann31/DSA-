class Solution {
public:
    string d2b(int n){
        string bin="";
        while(n>0){
            int bit=n%2;
            bin.push_back('0'+bit);
            n/=2;
        }
        reverse(bin.begin(),bin.end());
        return bin;
    }
    void check(string s,int &ans){
        int n=s.size();
        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')cnt0++;
            else cnt1++;
        }
        if(cnt1==n || cnt0==n){
            ans++;
        }
    }
    int countMonobit(int n) {
        int ans=0;
       for(int i=0;i<=n;i++){
         check(d2b(i),ans);
       }
       return ans;
       
    }
};