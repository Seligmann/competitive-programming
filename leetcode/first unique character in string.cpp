class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> m;
        vector<char> chars;
        int ret = INT_MAX;
        
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second == 1) {
                chars.push_back(it->first);
            }
        }
        
        for (int i = 0; i < chars.size(); i++) {
            int idx = find(s.begin(), s.end(), chars[i]) - s.begin();
            
            if (idx < ret) {
                ret = idx;
            }
        } 
        
        return (ret == INT_MAX) ? -1 : ret;
    }
};
