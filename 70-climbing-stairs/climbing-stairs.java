class Solution {
    int f(int n,List<Integer>dp){
        if(n<=1)return 1;
        if(dp.get(n)!=-1){
            return dp.get(n);
        }
        int ans=f(n-1,dp)+f(n-2,dp);
        dp.set(n,ans);
        return ans;
    }
    public int climbStairs(int n) {
        // List<Integer>dp = new ArrayList<>(Collections.nCopies(n+1,-1));
        // return f(n,dp);


        if(n<=1)return 1;
        List<Integer>dp = new ArrayList<>(Collections.nCopies(n+1,0));
        dp.set(0,1);
        dp.set(1,1);

        for(int i=2;i<=n;i++){
            int ans=dp.get(i-1)+dp.get(i-2);
            dp.set(i,ans);
        }
        return dp.get(n);
    }
}