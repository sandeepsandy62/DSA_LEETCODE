class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        
        '''
        
        1. We keep increasing the end of window until we find unique elements in the  string.
           Also, we'll calculate the max_length of the window.
           
        2. As soon as we encounter a repeated character, 
          our start of the window should be after the first occurance of this character.
          
          a b c a b c d
          0 1 2 3 4 5 6
          
          start = 0 , end = 3
          encountered a duplicate so , we need to move it to the next element of 
          first occurance of this character .
          start = 1 , end = 3
          
          that is how it works
          
          so we need map to store previous indexes of all elements
        
        '''
        
        start_index = 0 
        ans = 0
        mapping = {}
        for end_index in range(len(s)):
            if s[end_index] in mapping:
                start_index = max(start_index,mapping[s[end_index]]+1)
            mapping[s[end_index]] = end_index
            ans = max(ans,end_index-start_index+1)
        return ans