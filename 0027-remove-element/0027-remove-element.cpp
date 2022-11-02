class Solution {
    private :
    void swap(int &a , int &b){
        int temp = a ;
        a = b ;
        b = temp ;
    }
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0 , end = nums.size()-1;
        while(start <= end){
            if(nums[start] == val){
                if(nums[end]!=val)
                swap(nums[start],nums[end]);
                else{
                    end--;
                    continue;
                }
            }
            start++;
        }
        int cnt = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]!=val) cnt++;
            else break;
        }
        return cnt;
    }
};