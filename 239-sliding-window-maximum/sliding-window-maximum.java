class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n=nums.length;

        Deque<Integer>dq=new ArrayDeque<>();
        for(int i=0;i<k;i++){
            while(dq.size()>0 && nums[dq.peekLast()]<=nums[i]){
                dq.removeLast();
            }
            dq.addLast(i);
        }
        ArrayList<Integer>ans= new ArrayList<>();

        for(int i=k;i<n;i++){
            ans.add(nums[dq.peekFirst()]);

            int startIdx=i-k+1;
            while(!dq.isEmpty() && dq.peekFirst()<startIdx){
                dq.removeFirst();
            }

            while(!dq.isEmpty() && nums[dq.peekLast()] <= nums[i]){
                dq.removeLast();
            }

            dq.addLast(i);
        }
        ans.add(nums[dq.peekFirst()]);
        int[] arr=new int[ans.size()];

        for(int i=0;i<ans.size();i++){
            arr[i]=ans.get(i);
        }

        return arr;

    }
}