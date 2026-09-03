class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1>n2)return false;

        vector<int>freq1(26,0);
        vector<int>freq2(26,0);

        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
        }
        int l=0,r=0;
        while(r<n2){
            freq2[s2[r]-'a']++;

            while(r-l+1 > n1){
                freq2[s2[l]-'a']--;
                l++;
            }

            if(r-l+1 == n1){
                if(freq1==freq2){
                    return true;
                }
            }
            r++;
        }
        return false;


    }
};