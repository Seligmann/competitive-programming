class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        stk.push(s[0]);
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                stk.push(s[i]);
            else {
                if (stk.size() == 0) return false;
                
                if (s[i] == '}') {
                    if (stk.top() != '{')
                        return false;
                }
                else if (s[i] == ']') {
                    if (stk.top() != '[')
                        return false;
                }
                else if (s[i] == ')') {
                    if (stk.top() != '(')
                        return false;
                }
                
                stk.pop();
                
            }
        }
        
        if (stk.size() > 0) return false;
        
        return true;
    }
};
