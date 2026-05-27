class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        unordered_map<char,int>mpp1;//{lowerChar,last occurence index}
        unordered_map<char,int>mpp2;//{upperChar,first occurence index}

        for(int i=0;i<n;i++){
            char ch=word[i];
            if(ch>='a' && ch<='z'){
                mpp1[ch]=i;
            }else{
                if(mpp2.find(ch)==mpp2.end()){ //still not came
                mpp2[ch]=i;
                }
            }
        }
        set<char>st;
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z'){
                st.insert(word[i]);
            }
           
        }
        int ans=0;
        for(auto &it:st){
            char ch=it;
            char lo=it;
            char up=toupper(it);
            if(mpp2.find(up)!=mpp2.end()){
                if(mpp1[lo]<mpp2[up]){
                    ans++;
                }
            }
        }
        return ans;
    }
};