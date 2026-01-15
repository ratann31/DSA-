class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        auto lb=(int)(lower_bound(nums.begin(),nums.end(),target)-nums.begin());
        auto ub=(int)(upper_bound(nums.begin(),nums.end(),target)-nums.begin());

        if(lb==ub){ // el is not present 
            return {-1,-1};
        }else if(ub-lb==1){ //one time present only
            return {lb,lb};
        }
        return {lb,ub-1};

    }
};