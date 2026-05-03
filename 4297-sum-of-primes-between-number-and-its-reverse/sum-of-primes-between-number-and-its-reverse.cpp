class Solution {
public:
    bool isPrime(int n) {
    if (n <= 1) return false;        // 0 and 1 are not prime
    if (n == 2) return true;         // 2 is prime
    if (n % 2 == 0) return false;    // even numbers > 2 are not prime

    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return false;
    }
    return true;
}
    int sumOfPrimesInRange(int n) {
        string s=to_string(n);
        reverse(s.begin(),s.end());
        int r=stoi(s);
        int left=min(n,r);
        int right=max(n,r);
        int ans=0;
        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                ans+=i;
            }
        }
        return ans;

    }
};