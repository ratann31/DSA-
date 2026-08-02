class Solution {
public:
    bool isPalindrome(string &s,int left,int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void solve(int idx,string &s,vector<string>&path,vector<vector<string>>&ans){
        if(idx==s.size()){
            ans.push_back(path);
            return;
        }

        for(int end=idx;end<s.size();end++){
            if(isPalindrome(s,idx,end)){
                path.push_back(s.substr(idx,end-idx+1));
                solve(end+1,s,path,ans);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;

        solve(0,s,path,ans);

        return ans;
    }
};