class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.length() - 1;
        
        for (int i = 0; i < s.length(); i++) {
            if (j < i)
                break;
            if (iswalnum(s[i]) == 0)
                continue;
            while(iswalnum(s[j]) == 0)
                j--;
            
            if (isalpha(s[i]))
                s[i] = tolower(s[i]);
            if (isalpha(s[j]))
                s[j] = tolower(s[j]);
            
            if (s[i] != s[j])
                return false;
            
            j--;
        } 
        
        return true;
    }
};
