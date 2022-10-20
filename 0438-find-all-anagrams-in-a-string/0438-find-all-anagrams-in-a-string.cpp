class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int>ans;
        if(s.length() < p.length() || p.length() == 0) return ans;
        
        unordered_map<char,int>table;
        
        for(int i = 0 ; i < p.length() ; i++){
            table[p[i]]++;
        }
        
        int begin = 0 , end = 0 ,counter = table.size();
        
        while(end < s.length()){
            
            if(table.count(s[end]) == 1){
                
                table[s[end]]--;
                
                if(table[s[end]] == 0) counter-- ;
                
            }
            
            end++;
            
            while(counter == 0){
                
                if(end-begin == p.length()){
                    ans.push_back(begin);
                }
                
                int start = s[begin];
                
                if(table.count(start)==1){
                    table[start]++;
                    if(table[start] > 0) counter++;
                }
                
                begin++;
            }
            
        }
        return ans;
        
    }
};