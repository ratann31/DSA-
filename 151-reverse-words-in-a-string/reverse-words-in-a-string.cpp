class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string>temp;
        string word;
        while(ss>>word){
            temp.push_back(word);
        }
        reverse(temp.begin(),temp.end());
        string ans="";
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<temp[i].size();j++){
                ans+=temp[i][j];
            }
            ans+=" ";
        }
        ans.pop_back();
        return ans;
        
    }
};