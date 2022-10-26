class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        /*
        We are looking for the minimal k value satisfying nums[k] >= target, and Notice that our solution is correct regardless of whether the input array nums has duplicates. Also notice that the input target might be larger than all elements in nums and therefore needs to placed at the end of the array. That's why we should initialize right = len(nums) instead of right = len(nums) - 1.
        */
        int left = 0 , right = nums.size() ,mid; 
        while(left < right){
            mid = left + (right-left) / 2;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid+1;
        }
        return left ;
    }
};