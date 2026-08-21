class Solution {
    public String removeOuterParentheses(String s) {
        int n=s.length();
        String ans="";
        int cnt=0;
        for(int i=0;i<n;i++){
           if(s.charAt(i)==')'){
            cnt--;
           }
           if(cnt!=0){
            ans+=s.charAt(i);
           }
           if(s.charAt(i)=='('){
            cnt++;
           }
        }

        return ans;
    }
}