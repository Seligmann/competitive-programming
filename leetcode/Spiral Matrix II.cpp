class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        vector<vector<int>> visited(n, vector<int>(n));
      
        int x = 0;
        int y = 0;
        int val = 1;
        
        while (true) {
            cout << x <<  ' '<< y << ' ' << val << '\n';
            if (x != n - 1 && !visited[y][x+1] && (y == 0 || visited[y-1][x])) {
                ret[y][x] = val++;
                visited[y][x] = 1;
                x++;
            } else if (y != n - 1 && !visited[y+1][x] && (x == n - 1 || visited[y][x+1])) {
                ret[y][x] = val++;
                visited[y][x] = 1;
                y++;
            } else if (x != 0 && !visited[y][x - 1] && (y == n - 1 || visited[y+1][x])) {
                ret[y][x] = val++;
                visited[y][x] = 1;
                x--;
            } else if (y != 0 && !visited[y - 1][x] && (x == 0 || visited[y][x - 1])) {
                ret[y][x] = val++;
                visited[y][x] = 1;
                y--;
            } else {
                ret[y][x] = val;
                break;
            }
        }

        
        return ret;
    }
};
