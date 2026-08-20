class Solution {
    public String largestOddNumber(String num) {
        int n=num.length();

        String ans="";
        for(int i=n-1;i>=0;i--){
            if((num.charAt(i)-'0')%2==1){
                int len=n-(n-i)+1;
                return num.substring(0,len);
            }
        }

        return ans;
    }
}