class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        set<char> seen;
        queue<char> curr;
        
        for (int i = 0; i < s.length(); i++) {
            while (seen.find(s[i]) != seen.end()) {
                seen.erase(curr.front());
                curr.pop();
            }
            
            curr.push(s[i]);
            seen.insert(s[i]);
            
            longest = (curr.size() > longest) ? curr.size() : longest;
        }
        
        return longest;
    }
};
