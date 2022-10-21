class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> table;
        vector<int> ans;
        
        string sub[s.size()];
        for (int i = 0; i < s.size() - (int)words[0].size() + 1; i++)
            sub[i] = s.substr(i, (int)words[0].size());
        
        if(words.size() == 0) return ans;
        
        int window_size = 0;
        int word_size = words[0].length();
        
        // building frequency table
        for(string word : words){
            window_size += word.length();
            table[word]++;
        }
        
        
        
        int begin = 0, end = 0, counter = table.size();
        vector<string> tokens;
        
        if(s.length() < window_size) return ans;
        
        // we increment begin and end only in word_size 
        // there are only word_size possible start points for our window. 
        // end is actually the start of the last word in window or put in other words
        // the real end of window is actually at end + word_size
        for(int i = 0; i < word_size; i++){
            begin = i; end = i;
            counter = table.size();
            unordered_map<string, int> reference;
            
            while(end + word_size -1 < s.length()){
                reference[sub[end]]++;
                
                if(table.count(sub[end])){
                    if(reference[sub[end]] == table[sub[end]]) counter--;
                    
                    while(reference[sub[end]] > table[sub[end]]){
                        
                        if(reference[sub[begin]] == table[sub[begin]]) counter++;
                        
                        reference[sub[begin]]--;
                        begin += word_size;
                        
                    }
                    
                    if(counter == 0){
                        ans.push_back(begin);
                    }
                    
                    end += word_size ;
                    
                }else{
                    
                    end += word_size;
                    begin = end ;
                    reference.clear();
                    counter = table.size();
                    
                }
                
            }
        }
        
        return ans;
    }
};