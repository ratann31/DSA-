class Solution {
public:
    long long findLargestNo(int &num){
        string s = to_string(num);
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());

        long long res = stoll(s);
        return res;
    }
    long long maximizeSum(vector<int>& nums, int k) {
        int n=nums.size();
        long long totalSum=0;
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq; //{gain,index}

        for(int i=0;i<n;i++){
            totalSum+=nums[i];
            long long rev = findLargestNo(nums[i]);
            long long gain = rev-nums[i];

            if(gain>0){
                pq.push({gain,i});
            }

            if(pq.size()>k){
                pq.pop();
            }
            
        }

        while(!pq.empty()){
           totalSum+=pq.top().first;
           pq.pop();

        }

        return totalSum;
    }
};