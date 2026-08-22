class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n;
        long long sum=0;
        long long product=1;

        while(x>0){
            int lastDigit=x%10;
            sum+=lastDigit;
            product=1LL*lastDigit*product;

            x=x/10;
        }

        int total=sum+product;
        cout<<total;
        if(n%total==0){
            return true;
        }
        return false;
    }
};