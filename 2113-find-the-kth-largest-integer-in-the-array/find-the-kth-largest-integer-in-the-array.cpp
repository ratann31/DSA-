class Solution {
public:
    struct Compare{
        bool operator()(string &a,string &b){
            if(a.size()==b.size()){
                return a>b;
            }
            return a.size()>b.size();
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        int n=nums.size();

        priority_queue<string,vector<string>,Compare>pq;
        for(int i=0;i<n;i++){

            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }

        return pq.top();
    }
};