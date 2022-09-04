// time complexity: O(n)
// space complexity: O(n)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> rooms;
        
        sort(intervals.begin(), intervals.end());
        rooms.push(intervals[0][1]);
        
        for (int i = 1; i < intervals.size(); i++) { // meeting time requests
            if (intervals[i][0] >= rooms.top())
                rooms.pop();
            
            rooms.push(intervals[i][1]);
        }
        
        return rooms.size();
    }
};
