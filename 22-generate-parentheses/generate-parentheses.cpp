class Solution {
public:
    void solve(string curr,vector<string>&ans,int n,int open,int close){
        //base case
        if(curr.size()==2*n){
            ans.push_back(curr);
            return;
        }
        //take open
        if(open<n){
             curr.push_back('(');
            solve(curr,ans,n,open+1,close);
             curr.pop_back();
        }
       
        //take closed
        if(close<open){
             curr.push_back(')');
            solve(curr,ans,n,open,close+1);
             curr.pop_back();
        } 
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s="";
        int open=0,close=0;
        solve(s,ans,n,0,0);
        return ans;
    }
};