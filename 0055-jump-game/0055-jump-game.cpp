class Solution {
public:
    
    bool fun(vector<int>& nums,int i,vector<int>&dp){
        if(i == nums.size()-1){
            return true;
        }
        
        if(dp[i]!=-1) return dp[i];
        
        int reachable = i+nums[i];
        
        for(int k = i+1 ; k <= reachable ; k++){
            if(fun(nums,k,dp)) return dp[i]=true;
        }
       
        return dp[i] = false;
        
    }
    
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return fun(nums,0,dp);
    }
};