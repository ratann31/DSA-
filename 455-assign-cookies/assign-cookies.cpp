class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n=g.size();
        int m=s.size();

        int l=0,r=0;
        int ans=0;
        while(r<m && l<n){
            if(s[r]>=g[l]){ //cookie can be assigned 
                l++;
                r++;
                ans++;
            }else{
                r++;
            }
        }
        return l;
    }
};