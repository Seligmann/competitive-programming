class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> count(edges.size() + 2, 0);
        for (auto t : edges) {
            count[t[0]]++, count[t[1]]++;
            
            if (count[t[0]] == edges.size())
                return t[0];
            if (count[t[1]] == edges.size())
                return t[1];
        }
        
        return -1;
    }
};
