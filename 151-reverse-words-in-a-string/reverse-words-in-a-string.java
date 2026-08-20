class Solution {
    public String reverseWords(String s) {
        int n=s.length();

        s = new StringBuilder(s).reverse().toString();
        String ans="";
        for(int i=0;i<n;i++){
            String word="";

            while(i<n && s.charAt(i)!=' '){
                word+=s.charAt(i);
                i++;
            }
            word=new StringBuilder(word).reverse().toString();
            if(word.length()>0){
                ans+=" "+word;
            }
        }

        return ans.substring(1);
    }
}