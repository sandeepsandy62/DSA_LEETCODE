class Solution {
public:
    int thirdMax(vector<int>& nums) {
       set<int>st;
       for(int i = 0 ; i < nums.size() ; i++){
           st.insert(nums[i]);
       }
       vector<int>ans;
       for(auto x : st){
           ans.push_back(x);
       }
       sort(ans.begin(),ans.end(),greater<int>());
       int size = ans.size();
       if(size >= 3){
           return ans[2];
       }
       return ans[0];
    }
};