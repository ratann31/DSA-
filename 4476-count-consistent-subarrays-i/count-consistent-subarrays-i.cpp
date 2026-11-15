class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n=nums.size();
        
        int count=0;
        for(int i=0;i<n;i++){
            int mn=nums[i];
            int nd=nums[i];
            for(int j=i;j<n;j++){
                mn=min(nums[j],mn);
                nd=nd&nums[j];

                if(nd==mn){
                    count++;
                }
            }
        }
        return count;
    }
};