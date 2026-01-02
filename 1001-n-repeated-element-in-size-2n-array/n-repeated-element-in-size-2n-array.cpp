class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int x=nums.size();
        int n=x/2;
        map<int,int>mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int ans=-1;
        for(auto &it:mpp){
            if(it.second==n){
                ans=it.first;
                break;
            }
        }
        return ans;
    }
};