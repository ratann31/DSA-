class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize!=0)return false;
        map<int,int>mpp;//{num,freq}
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        while(!mpp.empty()){
            int currNum=mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                int nextConsecutive=currNum+i;
                if(mpp[nextConsecutive]==0){
                    return false;
                }
                mpp[nextConsecutive]--;
                if(mpp[nextConsecutive]<1){
                    mpp.erase(nextConsecutive);
                }
                
            }
        }
        return true;
    }
};