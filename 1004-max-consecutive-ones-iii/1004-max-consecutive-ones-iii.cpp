class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int len = 0 , maxrep = 0 , start = 0 ,end = 0 , n = nums.size() ;
        
        unordered_map<int,int>mp,lastseen;
        while(end < n){
           
            if(nums[end] == 1)
            mp[nums[end]]++;
            
            maxrep = max(maxrep,mp[nums[end]]);
            
            int curr_len = end - start+1;
            
            if(curr_len-maxrep > k){
                mp[nums[start]]--;
                start++;
            }
            curr_len = end-start+1;
            len = max(len,curr_len);
            
            end++;
           
        }
        return len;
    }
};