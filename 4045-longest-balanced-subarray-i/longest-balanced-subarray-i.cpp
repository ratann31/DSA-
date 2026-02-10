class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<n;i++){
            int len=0;
            set<int>odd,even;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0){
                    even.insert(nums[j]);
                }else{
                    odd.insert(nums[j]);
                }
                if(odd.size()==even.size()){
                    len=max(len,j-i+1);
                }
            }
            ans=max(ans,len);
        }
        return ans;
    }
};