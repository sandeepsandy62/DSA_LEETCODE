class Solution {
public:
    int characterReplacement(string s, int k) {
        
        //maxrep is max number of repeating elements
        
        int n = s.length() , start = 0 , end = 0 , maxrep = 0 , len = -1 ;
        
        unordered_map<char,int>mp;
        
        while(end < n){
            
            mp[s[end]]++;
            
            maxrep = max(maxrep,mp[s[end]]);
            
            int curr_len = end - start + 1;
            
            if(curr_len - maxrep > k){
                // k = 1 , AABABBA
                // AABAB => maxrep = 3 , curr_len = 5 , 5-3 > k so , we have to slide window
                //curr-len - max_rep 
                
                mp[s[start]]--;
                start++;
            }
            
            curr_len = end - start + 1; // just in case start changed 
            
            len = max(len,curr_len);
            
            end++;
            
            
        }
        
        return len;
    }
};