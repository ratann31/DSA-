class Solution {
public:
    bool isPalindrome(string &s){
        int l=0;
        int r=s.size()-1;

        while(l<=r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void f(string s,vector<string>&temp,vector<vector<string>>&ans){
       if(s.size()==0){
        ans.push_back(temp);
        return;
       }

       for(int i=0;i<s.size();i++){
        string part = s.substr(0,i+1);

        if(isPalindrome(part)){
            temp.push_back(part);
            f(s.substr(i+1),temp,ans);
            temp.pop_back();
        }
       }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;

        f(s,temp,ans);

        return ans;

    }
};