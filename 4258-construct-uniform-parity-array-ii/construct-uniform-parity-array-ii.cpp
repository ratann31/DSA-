class Solution {
public:
    bool checkOdd(vector<int>&arr){
        set<int>st;//store odd elements
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==1){
                st.insert(arr[i]);
                continue;
            }else{
                //check in map if there exist an element <= arr[i] and is odd element
                if(st.empty() || *st.begin()>=arr[i]){
                    return false;
                }
            }
        }
        return true;
    }
    bool checkEven(vector<int>&arr){
        set<int>st;//stores all odd elements
        for(int i=0;i<arr.size();i++){
            if(arr[i]%2==0){
                continue;
            }else{
                if(st.empty() || *st.begin()>=arr[i]){
                    return false;
                }
               
            }
            st.insert(arr[i]);
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        sort(nums1.begin(),nums1.end());
        bool allOdd=checkOdd(nums1);
        bool allEven=checkEven(nums1);

        return allOdd||allEven;
    }
};