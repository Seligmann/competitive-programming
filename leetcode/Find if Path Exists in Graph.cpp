class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> m(n);
        vector<int> seen(n);
        for (auto& vertex : edges) {
            m[vertex[0]].push_back(vertex[1]);
            m[vertex[1]].push_back(vertex[0]);
        }
        return dfs(seen, source, destination, n, m);
    }
    
    bool dfs(vector<int>& seen, int curr, int dest, int n, vector<vector<int>>& m) {
        auto destMapIt = find(m[dest].begin(), m[dest].end(), curr);
        
        if (curr == dest && n == 1)
            return true;
        
        if (destMapIt != m[dest].end())
            return true;
        else {
            for (auto val : m[curr]) {
                if (seen[val] == 0) {
                    seen[val]++;
                    if (dfs(seen, val, dest, n, m))
                        return true;
                }
            }
        }
        return false;
    }
};
