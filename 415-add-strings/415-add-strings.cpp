class Solution {
    private:
    void swaps(string &s , int low , int high){
        char temp = s[low];
        s[low] = s[high];
        s[high] = temp ;
    }
    
    void reverse(string &s){
        int low = 0 , high = s.length()-1;
        while(low <= high){
            swaps(s,low,high);
            low ++ ;
            high --;
        }
    }
    
public:
    string addStrings(string num1, string num2) {
        string ans ="";
        
        //To handle unequal length eg:
        //108 
        //9
        reverse(num1);
        reverse(num2);
        
        //Normal addition until one or both of the strings get completed
        int carry = 0 , sum = 0;
        int i = 0 , j = 0 , n = num1.length() , m = num2.length() ,temp = 0 ;
        while(i < n && j < m){
            sum = num1[i]-'0' + num2[j]-'0' + carry ;
            temp = sum%10 ;
            ans += (temp+'0');
            carry = sum/10 ;
            i++ , j++ ;
        }
        
        //until carry becomes zero 
        //make sure to initialize sum = 0 every time
        while(i<n || j<m || carry!=0){
            sum = 0;
            if(i < n)
            sum = num1[i++]-'0' ;
            else if(j < m)
            sum = num2[j++]-'0';
            
            sum += carry;
            temp = sum%10 ;
            ans += (temp+'0');
            carry = sum/10 ;
        }
        
        //make sure to reverse and return the ans
        reverse(ans);
        return ans;
    }
};