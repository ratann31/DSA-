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
                    //water will be trapped here and will depend upon lmax
                    //trapped water=lmax-ht[l]
                    int trappedWater=lmax-height[l];
                    ans+=trappedWater;
                }else{
                    lmax=height[l];
                }
                l++;
            }else{
                if(height[r]<=rmax){
                    //water will be trapped here and will depend upon rmax
                    //trapped water=rmax-ht[r]
                    int trappedWater=rmax-height[r];
                    ans+=trappedWater;
                }else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return ans;
    }
};