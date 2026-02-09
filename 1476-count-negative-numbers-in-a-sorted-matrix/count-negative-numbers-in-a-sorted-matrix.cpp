class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        int ans=0;
        for(int i=0;i<R;i++){
            //find first element idx which is less than or equal to 0
            auto idx=upper_bound(grid[i].begin(),grid[i].end(),0,greater<int>())-grid[i].begin();
            ans+=C-idx;
        }
        return ans;
        
    }
};