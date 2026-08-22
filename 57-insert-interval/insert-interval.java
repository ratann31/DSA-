class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        ArrayList<int []>ans=new ArrayList<>();
        int n=intervals.length;
        //store interval before overlap
        int idx=0;
        while(idx<n && newInterval[0] > intervals[idx][1] ){
            ans.add(intervals[idx]);
            idx++;
        }
        //merge overlapping intervals if any
        while(idx<n && newInterval[1]>=intervals[idx][0]){
          newInterval[0]=Math.min(newInterval[0],intervals[idx][0]);
          newInterval[1]=Math.max(newInterval[1],intervals[idx][1]);

          idx++;
        }
        ans.add(newInterval);

        while(idx<n){
            ans.add(intervals[idx]);
            idx++;
        }

        return ans.toArray(new int [ans.size()][2]);

       
    }
}