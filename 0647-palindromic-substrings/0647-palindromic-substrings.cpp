class Solution {
public:
    int countPali(int start , int end , string s){
        int res = 0 ;
        while(start >= 0 && end < s.length() && s[start]==s[end]){
            res += 1 ;
            start -= 1;
            end += 1;
        }
        return res;
    }
    
    int countSubstrings(string s) {
        int res = 0;
        int len = s.length();
        for(int i = 0 ; i < len ; i++){
            //assuming i as centre and expanding left and right , this gives odd length (i-1,i,i+1)
            res += countPali(i,i,s);
            //assuming i as centre and expanding left and right , this gives even length(i-1,[i,i+1],(i+1)+1)
            res += countPali(i,i+1,s);
        }
        return res;
    }
};