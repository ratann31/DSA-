class Solution {
public:
    int findProduct(int n){
        int temp=1;
        while(n>0){
            int last=n%10;
            temp=temp*last;
            n=n/10;
        }
        return temp;
    }
    int smallestNumber(int n, int t) {
        int x=n;
        bool found=false;
        int ans;
        while(!found){
            int p=findProduct(x);
            if(p%t==0){
                found=true;
                ans=x;
            }else{
                x++;
            }
        }
        return ans;
    }
};