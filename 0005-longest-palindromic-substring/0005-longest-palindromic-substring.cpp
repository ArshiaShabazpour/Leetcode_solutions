class Solution {
public:
    string longestPalindrome(string s) {
        int idx=0;
        int maxlen=0;
        int i=0;
        int n=s.size();
        while(i<n){
            int l=i;
            while(i+1<n && s[i]==s[i+1]){
                i++;
            }
            int r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                l--;
                r++;
            }
            int len = r-l-1;
            if(len>maxlen){
                 idx = l+1;
                 maxlen = len;
            }
            i++;  
        }
        return s.substr(idx,maxlen);
    }
};