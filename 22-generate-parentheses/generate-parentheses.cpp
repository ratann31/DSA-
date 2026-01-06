class Solution {
public:
    bool isValid(string s){
        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt<0){
                return false;
            }
        }
        if(cnt==0){
            return true;
        }
        return false;
    }
    void solve(string curr,vector<string>&ans,int n){
        //base case
        if(curr.size()==2*n){
            if(isValid(curr)){
                ans.push_back(curr);
            }
            return;
        }
        //take open
        curr.push_back('(');
        solve(curr,ans,n);
        curr.pop_back();
        //take closed
        curr.push_back(')');
        solve(curr,ans,n);
        curr.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        solve(s,ans,n);
        return ans;
    }
};