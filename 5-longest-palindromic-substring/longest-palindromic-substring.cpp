class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        string res="";
        //odd length ke liye
            for(int ax=0;ax<n;ax++){
                int orb=1;
                int len=1;

                while(ax-orb>=0 && ax+orb<n){
                    if(s[ax-orb]==s[ax+orb]){
                        orb+=1;
                        len+=2;
                    }else{
                        break;
                    }
                }

                if(len>res.size()){
                    int startIdx=ax-len/2;
                    res=s.substr(startIdx,len);
                }
            }
        //even length ke liye
        for(int ax=0;ax<n-1;ax++){
            int orb=1;
            int len=0;

            while(ax-orb+1 >=0 && ax+orb<n){
                if(s[ax-orb+1]==s[ax+orb]){
                    orb+=1;
                    len+=2;
                }else{
                    break;
                }
            }

            if(len>res.size()){
                int startIdx=ax-len/2+1;
                res=s.substr(startIdx,len);
            }
        }
        return res;

    }
};