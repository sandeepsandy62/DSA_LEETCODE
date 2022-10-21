class Solution {
public:  
    bool check(int i , string s,unordered_map<string,int>&table,int k, int wordLength,int substringSize){
        unordered_map<string ,int>reference(table);
        int counter = k;
        
        for(int j = i ; j < i+substringSize ; j += wordLength){
            string sub = s.substr(j,wordLength);
            if(reference[sub] != 0){
                reference[sub]--;
                counter--;
            }else{
                break;
            }
        }
        
        return counter == 0;
        
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int k ;
        int n ;
        int wordLength;
        int substringSize;
        n = s.length();
        k = words.size();
        
        wordLength = words[0].length();
        substringSize = k*wordLength;
        
        unordered_map<string,int>table;
        for(string word : words){
            table[word]++;
        }
        
        vector<int>ans;
        for(int i = 0 ; i < n - substringSize+1 ; i++){
            if(check(i,s,table,k,wordLength,substringSize)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};