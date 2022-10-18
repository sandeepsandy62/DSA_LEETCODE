class Solution:
    def maxArea(self, height: List[int]) -> int:
        i, j = 0, len(height) - 1
        water = 0
        while i < j:
            water = max(water, (j - i) * min(height[i], height[j]))
            if height[i] < height[j]:
                i += 1
            else:
                j -= 1
        return water
    
    '''
    when h[i] == h[j]
       it does not matter if you do i++ or j--
       after that width is going to decrease in any way
       but area more depends on height here if future height is small area decreases than the current 
       if height increases also  area decreases because we consider small height
       so , either way we are going to get less area than the current one
    '''
