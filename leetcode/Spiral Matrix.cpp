class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        vector<vector<int>> visited(matrix.size() * matrix[0].size(), vector<int>(matrix[0].size(), 0));
        
        int top = 0;
        int bot = matrix.size() - 1;
        int x = 0;
        int y = 0;
        
        while (true) {
            // cout << x << ' ' << y << ' '<< matrix[y][x] << ' '<<  visited[y][x] << '\n';
            ret.push_back(matrix[y][x]);
            visited[y][x] = 1;
            
            if (x != visited[0].size() - 1 && !visited[y][x + 1] && (y == 0 || visited[y-1][x])) {
                x++;
            } else if (x != 0 && !visited[y][x - 1] && (y == matrix.size() - 1 || visited[y+1][x])) {
                x--;
            } else if (y != visited.size()/visited[0].size() - 1 && !visited[y + 1][x]) {
                y++;
            } else if (y != 0 && !visited[y - 1][x]) {
                y--;
            } else {
                break;
            }
        }
        
        return ret;
    }
};
