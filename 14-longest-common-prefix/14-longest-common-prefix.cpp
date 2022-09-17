class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        //if string size is zero then return empty string
        if(strs.size() == 0)
        return "";
        
        string ans = "";
        
        //here the catch is if we sort the array of string
        //we will be getting a array of lexicographically ordered strings
        //so adjacent strings wont diff much
        //so instead of checking all strings , anyway we need a longest COMMON prefix
        //so we directly check first and last so there will be a lot of difference
        
        sort(strs.begin(),strs.end());
        
        string a = strs[0];
        string b = strs[strs.size()-1];
        
        //self explanatory
        for(int i = 0 ; i < a.length() ; i++){
            if(a[i] == b[i]) ans+=a[i];
            else break;
        }
        
        return ans;
    }
};