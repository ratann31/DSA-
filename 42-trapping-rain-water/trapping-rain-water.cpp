class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();

        int lmax=0,rmax=0;
        int l=0,r=n-1;

        int ans=0;

        while(l<=r){
           if(height[l]<=height[r]){
                if(height[l]<=lmax){
                    int water=lmax-height[l];
                    ans+=water;
                }else{
                    lmax=height[l];
                }
                l++;
           }else{
                if(height[r]<=rmax){
                    int water=rmax-height[r];
                    ans+=water;
                }else{
                    rmax=height[r];
                }
                r--;
           }
        }
        return ans;
    }
};