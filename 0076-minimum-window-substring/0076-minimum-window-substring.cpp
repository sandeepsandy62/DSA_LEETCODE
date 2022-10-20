class Solution {
public:
    string minWindow(string s, string t) {
        
        string ans = "";
        unordered_map<char,int>table;
        
        
        for(int i = 0 ;i < t.length() ;i++){
            
            table[t[i]]++;
            
        }
        
        int begin = 0 , end = 0 , counter = table.size() , len = INT_MAX ;
        
        while(end < s.length()){
            
            if(table.find(s[end]) != table.end()){
                
                table[s[end]]--;
                
                if(table[s[end]] == 0) counter--;
                
            }
            
            end++;
            
            while(counter == 0){
                
                if(end-begin < len){
                    
                    len = end-begin;
                    ans = s.substr(begin,end-begin);
                    
                }
                
                int startchar = s[begin];
                
                if(table.count(startchar)==1){
                    table[startchar]++;
                    if(table[startchar] > 0) counter++;
                }
                
                begin++;
            }
            
        }
        
        return ans;
    }
};