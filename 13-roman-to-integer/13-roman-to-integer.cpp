class Solution {
public:
    int romanToInt(string s) {
        //Logic is Roman numerals are usually written largest to smallest from left to right.
        // We will traverse from back to front if(i < i+1) we will perform subtraction
        //else we just add them
        //TC : O(N) , SC : O(1) ..if we not consider map else it is O(N)
        unordered_map<char,int>mp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        int num = mp[s.back()];
        int len = s.length();
        for(int i = len-2 ; i >= 0 ; i--){
            if(mp[s[i]] < mp[s[i+1]]) num-=(mp[s[i]]) ;
            else num+=mp[s[i]];
        }
        return num;
    }
};