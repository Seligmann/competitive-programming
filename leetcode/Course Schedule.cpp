class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (numCourses == 1) return true;
        if (prerequisites.size() == 0) return true;
        
        map<int, vector<int>> courses;
        vector<bool> notCycle(numCourses, 0);
        
        // build graph
        for (int i = 0; i < prerequisites.size(); i++) {
            courses[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        // traverse, checking for cycles
        for (map<int, vector<int>>::iterator it = courses.begin(); it != courses.end(); it++) {
            if (notCycle[it->first]) continue;
            vector<bool> visited(numCourses, 0);
            
            if (isCycle(it->first, it->second, visited, courses, notCycle))
                return 0;
        }
        
        return 1;
    }
    
    bool isCycle(int key, vector<int>& vals, vector<bool>& visited, map<int,vector<int>>& courses, vector<bool>& notCycle) {
        if (visited[key])
            return 1;
        
        if (notCycle[key])
            return 0;
        
        if (vals.size() == 0)
            return 0;
        
        visited[key] = 1;
        
        // go thru all next courses of curr pre req
        bool ret = false;
        for (int i = 0; i < vals.size(); i++) {
            if (notCycle[vals[i]]) continue;
            
            ret = isCycle(vals[i], courses[vals[i]], visited, courses, notCycle);
            if (ret)
                break;
            
            notCycle[vals[i]] = 1;
            
        }
        
        visited[key] = 0;
        notCycle[key] = 1;
        
        return ret;
    } 
};
