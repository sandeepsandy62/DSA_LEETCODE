class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        '''
        0,0,1,1,1,2,2,3,3,4
        0 1 2 3 4 5 6 7 8 9
        
        Now , l = 0 , r = l+1 : init
        if a[l] == a[r] : r+=1
        else swap(a[l+1],a[r]) l+=1 , r+=1
        
        until r < n
        
        '''
        left = 1 
        for right in range(len(nums)-1):
            if nums[right]!=nums[right+1]:
                nums[left] = nums[right+1]
                left+=1
        return left