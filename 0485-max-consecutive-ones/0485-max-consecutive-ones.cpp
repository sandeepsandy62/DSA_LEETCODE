class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = 0 , end = 0 , len = 0 , n = nums.size();
        
        while(end < n){
            if(nums[end] == 0){
               start = end+1;
            }
            end++;
            len = max(len , end-start);
        }
        return len; 
    }
};