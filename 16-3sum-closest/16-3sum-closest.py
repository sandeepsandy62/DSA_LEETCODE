class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        
        '''
         ==> sort array in increasing order , so that using 2 pointers becomes easy
         ==> nums[i] by iterating i in range [0..n-2], we using 2 pointers to find 2 elements in
             range [i+1..n-1], so that nums[i] + nums[l] + nums[r] will have minimum 
             difference with our target.
        '''
        diff = 1e9
        ans  = 1e9
        temp = nums[0] + nums[1] + nums[2] 
        
        if temp > target:
            return temp
        
        for i in range(n-2):
            l , r = i+1 , n-1
            while l < r :
                sum3 = nums[i] + nums[l] + nums[r] 
                
                a = abs(target-sum3)
                
                if a < diff:
                    diff = a
                    ans = sum3
                
                
                if sum3 > target:
                    r -= 1
                else:
                    l += 1
            if diff == 0:
                break
        return ans 