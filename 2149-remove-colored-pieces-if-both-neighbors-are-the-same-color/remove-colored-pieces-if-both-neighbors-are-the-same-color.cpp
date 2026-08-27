class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();

        int countAAA=0;
        int countBBB=0;

        for(int i=1;i<n-1;i++){
            if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A'){
                countAAA++;
            }
            if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B'){
                countBBB++;
            }
        }

        if(n<3){
           return false;
        }

        if(countAAA>countBBB){
            return true;
        }
        return false;
    }
};