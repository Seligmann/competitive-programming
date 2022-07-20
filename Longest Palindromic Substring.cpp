class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0;
        int len = 0;
        
        if (s.length() == 1) {
            return s;
        }
        
        if (s.length() == 2 && s[0] != s[1]) {
            string ret(1, s[0]);
            return ret;
        } else if (s.length() == 2 && s[0] == s[1]) {
            return s;
        }
        
        for (int i = 0; i < s.length(); i++) {
            int l, r;
            l = r = i;
            while (r < s.length() && l >= 0 && s[r] == s[l]) {
                if (len < r - l + 1) {
                    begin = l;
                    len = r - l + 1;
                }
                r++;
                l--;
            }
            
            r = i + 1;
            l = i;
            while (l >= 0 && r < s.length() && s[r] == s[l]) {
                if (len < r - l + 1) {
                    begin = l;
                    len = r - l + 1;
                }
                r++;
                l--;
            }
        }
        
        return s.substr(begin, len);
    }
};
