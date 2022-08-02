class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using vectors to keep track of each values freq doesn't work because you can have negative values
        map<int, int> freq;
        map<int, int> freqIdx;
        priority_queue<pair<int,int>> sortedFreq;
        vector<int> ret;
        
        for (int i = 0; i < nums.size(); i++)
            freq[nums[i]]++;
        
        for (auto it = freq.begin(); it != freq.end(); it++)
            freqIdx[it->second] = it->first;
        
        for (auto it = freq.begin(); it != freq.end(); it++)
            sortedFreq.push(make_pair(it->second, it->first));
        
        for (int i = 0; i < k; i++) {
            ret.push_back(sortedFreq.top().second);
            sortedFreq.pop();
        }
        
        return ret;
    }
};
