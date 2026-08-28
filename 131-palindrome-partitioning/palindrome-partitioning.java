class Solution {
    boolean isPalindrome(String s){
        int left=0;
        int right=s.length()-1;

        while(left<=right){
            if(s.charAt(left)!=s.charAt(right))return false;
            left++;
            right--;
        }
        return true;
    }
    void f(String s,List<String>path,List<List<String>>ans,int n){
        if(s.length()==0){
            ans.add(new ArrayList<>(path));
            return;
        }

        for(int idx=0;idx<s.length();idx++){
            String part=s.substring(0,idx+1);

            if(isPalindrome(part)){
                path.add(part);
                f(s.substring(idx+1),path,ans,n);

                path.remove(path.size()-1);
            }
        }
    }
    public List<List<String>> partition(String s) {
        int n=s.length();
        List<List<String>>ans=new ArrayList<>();
        List<String>path=new ArrayList<>();

        f(s,path,ans,n);

        return ans;
    }
}