class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        vector<vector<string>>ans;

        int i=0,j=0;
        string temp1="";
        string temp2="";

        while(i<n1 && j<n2){
            if(s1[i]==s2[j]){
                if(!temp1.empty() && !temp2.empty()){
                    ans.push_back({temp1,temp2});
                    temp1="";
                    temp2="";
                }
            }else{
                temp1+=s1[i];
                temp2+=s2[j];
            }
            i++;
            j++;
        }
        if(!temp1.empty() && i>=n1-1){
            ans.push_back({temp1,temp2});
        }
        return ans;
        
    }
};