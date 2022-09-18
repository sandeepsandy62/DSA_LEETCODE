class Solution {
public:
    int search(vector<int>& nums, int target) {
        //traditional binary search
        long long int low = 0 , high = nums.size()-1;
        while(low <= high){
            long long int mid = low + (high-low)/2 ;
            
            if(nums[mid] == target) return mid;
            
            if (nums[mid] < target) low = mid+1;
            else high = mid-1;
            
        }
        return -1;
    }
};