class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n=text.size();
        int b=0,a=0,l=0,o=0,nn=0;
        for(int i=0;i<n;i++){
            if(text[i]=='b'){
                b++;
            }else if(text[i]=='a'){
                a++;
            }else if(text[i]=='l'){
                l++;
            }else if(text[i]=='o'){
                o++;
            }else if(text[i]=='n'){
                nn++;
            }
        }
        int cnt=0;
        int x1=min({b,a,nn});
        int x2=min({l,o});

        int x3=x2/2;
        return min(x1,x3);

    }
};