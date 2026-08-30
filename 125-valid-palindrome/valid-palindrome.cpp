class Solution {
public:
    bool check(string s){
        int n=s.size();
        int left=0,right=n-1;
        while(left<=right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string temp="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                temp+=s[i];
            }
        }
        for(int i=0;i<temp.size();i++){
            temp[i]=tolower(temp[i]);
        }

        return check(temp);
    }
};