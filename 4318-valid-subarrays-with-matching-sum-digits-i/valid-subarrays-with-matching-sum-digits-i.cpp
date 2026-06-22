class Solution {
public:
    using ll = long long;
    ll firstDigit(ll n) {
    ll digits = log10(n);
    return n / pow(10, digits);
    }
    int countValidSubarrays(vector<int>& nums, int x) {
        ll n=nums.size();
        ll cnt=0;
        for(int i=0;i<n;i++){
            ll sum=0;
            for(int j=i;j<n;j++){
                sum+=nums[j];
                ll last=sum%10;
                ll first=firstDigit(sum);

                if(last==x && first==x){
                    cnt++;
                }
            }
        }
        return (int)cnt;
    }
};