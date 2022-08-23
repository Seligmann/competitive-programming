class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // go thru nums, count occurs of each unique num, using a map to keep track of each unique num and its occurance
        // using a priority queue, push the num of occurs
        // iterate through the map of nums and their occurs, and create a multimap with (second, first)
        // until ret vector is size k, index the multimap with the priority que top, then remove that index in the multimap
        map<int, int> occurs;
        vector<int> ret;
        priority_queue<int> sortedOccurs;
        multimap<int, int> idxOccurs;
        
        for (int i = 0; i < nums.size(); i++) {
            occurs[nums[i]]++;
        }
        
        for (auto it = occurs.begin(); it != occurs.end(); it++) {
            idxOccurs.insert(pair<int,int>(it->second, it->first));
        }
        
        for (auto it = occurs.begin(); it != occurs.end(); it++) {
            sortedOccurs.push(it->second);
        }
        
        while (ret.size() != k) {
            // int currTop = sortedOccurs.top();
            ret.push_back(idxOccurs.find(sortedOccurs.top())->second);
            idxOccurs.erase(idxOccurs.find(sortedOccurs.top()));
            sortedOccurs.pop();
        }
        
        return ret;
    }
};
