class Solution {
public:
    void dfs(int idx,int n,int k,int cost,string &s,vector<string>&ans){
        if(cost>k){
            return;
        }
        if(idx==n){
            ans.push_back(s);
            return;
        }
        //put 0
        s.push_back('0');
        dfs(idx+1,n,k,cost,s,ans);
        s.pop_back();
        
        if(idx==0 || s.back()!='1'){
            s.push_back('1');
            dfs(idx+1,n,k,cost+idx,s,ans);
            s.pop_back();
        }
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string>ans;
        string s="";
        dfs(0,n,k,0,s,ans);
        return ans;
    }
};