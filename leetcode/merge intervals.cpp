class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        
        for (int i = 0; i < intervals.size(); i++) {
            if (ret.empty() || intervals[i][0] > ret[ret.size() - 1][1]) {
                // cout << "intervals[i][0]: " << intervals[i][0] << " intervals[i - 1][1]: " << intervals[i - 1][1] << "\n";
                ret.push_back(intervals[i]);
            } else {
                ret[ret.size() - 1][1] = max(ret[ret.size() - 1][1], intervals[i][1]);
            }
        }
        
        return ret;
    }
};
