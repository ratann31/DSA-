class Solution {
public:
    string removeOuterParentheses(string s) {
        vector<pair<int,int>>range;
        int cnt = 0;
        int l=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                cnt++;
            }else if(s[i]==')'){
                cnt--;
            }
            if(cnt==0){
                range.push_back({l,i});
                l=i+1;
                cnt = 0;
            }
        }
        string ans="";
        for(int i=0;i<range.size();i++){
            int a=range[i].first;
            int b=range[i].second;

            for(int i=a+1;i<=b-1;i++){
                ans+=s[i];
            }
        }
        return ans;
    }
};