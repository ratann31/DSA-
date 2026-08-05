class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jumps=0;
        int farthest=0;
        int currEnd=0;

        for(int i=0;i<n-1;i++){
            int maxIndex=i+nums[i];
            farthest=max(farthest,maxIndex);

            if(i==currEnd){
                jumps++;
                currEnd=farthest;
            }
        }

        return jumps;
    }
};