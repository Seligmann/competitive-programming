class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> v;
        
        for (int i = 0; i < strs.size(); i++) {
            // sort char and check if its in hashmap
                // if in hashmap, map to correct value
                // if not in hashmap, add to it
            
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            
            if (m.find(sortedWord) == m.end())
                m[sortedWord] = {strs[i]};
            else
                m[sortedWord].push_back(strs[i]);
        }
        
        for (auto it : m)
            v.push_back(it.second);
        
        return v;
    }
};
