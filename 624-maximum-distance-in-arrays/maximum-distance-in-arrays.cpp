class Solution {
public:
    int findMax1(vector<vector<int>>& arrays){
        int maxi=INT_MIN;
        int mini=INT_MAX;

        int maxIdx=-1;
        for(int i=0;i<arrays.size();i++){
            int lastEl=arrays[i][arrays[i].size()-1];

            if(lastEl>maxi){
                maxi=lastEl;
                maxIdx=i;
            }
        }
        int minIdx=-1;
        for(int i=0;i<arrays.size();i++){
            int firstEl=arrays[i][0];

            if(firstEl<mini && i!=maxIdx){
                mini=firstEl;
                minIdx=i;
            }
        }
        return maxi-mini;
    }
    int findMax2(vector<vector<int>>& arrays){
        int maxi=INT_MIN;
        int mini=INT_MAX;

        int minIdx=-1;
        for(int i=0;i<arrays.size();i++){
            int firstEl=arrays[i][0];

            if(firstEl<mini){
                mini=firstEl;
                minIdx=i;
            }
        }
        int maxIdx=-1;
        for(int i=0;i<arrays.size();i++){
            int lastEl=arrays[i][arrays[i].size()-1];

            if(lastEl>maxi && i!=minIdx){
                maxi=lastEl;
                maxIdx=i;
            }
        }
        return maxi-mini;
    }
    int maxDistance(vector<vector<int>>& arrays) {
        
        int ans1=findMax1(arrays);
        int ans2=findMax2(arrays);

        return max(ans1,ans2);


    }
};