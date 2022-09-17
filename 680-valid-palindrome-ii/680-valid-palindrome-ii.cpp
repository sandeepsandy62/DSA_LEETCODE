class Solution {
    private : 
    
    //traditional palindrome checker algorithm
    bool isPalindrome(string s , int low , int high){
        while(low <= high){
            if(s[low] == s[high]) low++,high--;
            else return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        
        /* here the logic is if both low and high are same them we move forward
           else we will check once if we remove low element is it a palindrome
           or if we remove high element is it a palindrome if any of these is 
           true . then we satisfied our condition atmost one character can be deleted
           to make a palindrome .so , this is it ! */
        
        
        int low = 0 , high = s.length()-1 ;
        while(low <= high){
            if(s[low] == s[high]) low++,high--;
            else return isPalindrome(s,low,high-1) || isPalindrome(s,low+1,high);
        }
        
        return true;
    }
};