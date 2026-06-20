class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int>sorted(n);

        for(int r=0;r<=n;r++){
            int idx=0;
            for(int i=r;i<n;i++){
                sorted[idx]=nums[i];
                idx++;
            }

            for(int i=0;i<r;i++){
                sorted[idx]=nums[i];
                idx++;
            }
            if(is_sorted(sorted.begin(),sorted.end())){
            return true;
        }
        }
      
        return false;
    }
};