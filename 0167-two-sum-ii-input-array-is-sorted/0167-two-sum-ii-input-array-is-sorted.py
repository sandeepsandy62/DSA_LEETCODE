class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        '''
        1 . take 2 pointers left and right
        2 . left = 0 , right = numbers.size() - 1
        3 . sum = add numbers[left] and numbers[right]
        4 . if this sum is greater than target then there is no point of pointing right at end
            cause we already know that array in non-decreasing order
        5 . so , right--
        6 . if sum < target then left++
        7 . repeat it until left < right
        8 . after crossing left and right then there is no point of repeating it again
        
        '''
        
        sum = 0
        left , right = 0 , len(numbers)-1
        while(left < right):
            if numbers[left]+numbers[right] > target:
                right-=1;
            elif numbers[left]+numbers[right] < target:
                left+=1;
            else:
                return [left+1,right+1]
        
        