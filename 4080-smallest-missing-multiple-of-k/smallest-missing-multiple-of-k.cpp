class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        int i=1;
        while(true){
            if(mpp.find(k*i)!=mpp.end()){
                i++;
            }else{
                return k*i;
            }
        }
        return -1;
    }
};