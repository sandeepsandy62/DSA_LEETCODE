class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        int l = s.length();
        for(int i = 0 ; i < l ; i++){
            if(s[i]=='['||s[i]=='{'||s[i]=='('){
                stk.push(s[i]);
            }else{
                if(stk.empty()) return false;
                if(s[i]==']' && stk.top()!='[') return false;
                if(s[i]==')' && stk.top()!='(') return false;
                if(s[i]=='}' && stk.top()!='{') return false;
                stk.pop();
            }
        }
        return stk.empty();
    }
};