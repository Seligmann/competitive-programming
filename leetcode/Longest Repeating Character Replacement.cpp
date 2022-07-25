class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int v[26] = {0};
        int maxCount = 0;
        int max = 0;
        
        for (int r = l; r < s.length(); r++) {
            v[s[r] - 'A']++;
            maxCount = (maxCount > v[s[r] - 'A']) ? maxCount : v[s[r] - 'A'];
            
            while (l <= r && r - l + 1 - maxCount > k) {
                v[s[l] - 'A']--;
                l++;
            }
            max = (r - l + 1 > max) ? r - l + 1 : max;
                
        }
        
        return max;
    }
};
