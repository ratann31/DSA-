class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int left=0,right=n-1;
        int x=n/2;
        while(x--){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};