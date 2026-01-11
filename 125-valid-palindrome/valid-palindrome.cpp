class Solution {
public:
    bool isAlphaNum(char ch){
        return (ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9');
    }
    bool checkPalindrome(string s){
        int n=s.size();
        int l=0,r=n-1;
        for(int i=0;i<n/2;i++){
            if(s[l]!=s[r])return false;
            l++;
            r--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        string temp="";
        for(auto &it:s){
            it=tolower(it);
        }
        cout<<temp<<endl;
        for(int i=0;i<n;i++){
            if(isAlphaNum(s[i])){
                temp+=s[i];
            }
        }
        //cout<<temp<<endl;
        return checkPalindrome(temp);
    }
};