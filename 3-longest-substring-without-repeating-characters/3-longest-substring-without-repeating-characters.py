class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        usedchar = {}
        start = ans = 0
        n = len(s)
        for i in range(n):
            if s[i] in usedchar and start <= usedchar[s[i]]:
                start = usedchar[s[i]]+1
            else:
                ans = max(ans , i-start+1)
                
            usedchar[s[i]] = i
            
        return ans