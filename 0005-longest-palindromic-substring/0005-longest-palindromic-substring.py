class Solution:
    def longestPalindrome(self, s: str) -> str:
        '''
        brute force way of solving this problem is 
        finding all the substrings and checking every substring if it is a palindrome or not
        if it is then find the longest one 
        if we talk about time complexity , O(n^2) for findign all substrings 
        and O(n) for checking it is a palindrome or not
        so , whole complexity is O(n^3)
        
        In brute force we are searching doing redundant checks 
        so , here is another approach
        assume for every character we are expanding our window to left and right simultanioulsy
        leftchar<--------------centre char ------------------>rightchar
        if centre is a plaindrome then check left and if they are equal or not
        but by doing this we need to handle the edge case when longest palindrome is of even length
        
        '''
        
        res = ""
        resLen = 0 
        
        for i in range(len(s)):
            
            #odd length
            l , r = i , i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if(r-l+1 > resLen):
                    res = s[l:r+1]
                    resLen = r-l+1
                l -= 1
                r += 1
            
            #even length
            l , r = i , i+1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                if(r-l+1 > resLen):
                    res = s[l:r+1]
                    resLen = r-l+1
                l -= 1
                r += 1
                
        return res