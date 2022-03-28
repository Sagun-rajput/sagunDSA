class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {   
      unordered_map<string,int> map;
        return uniquePaths(0, 0, obstacleGrid.size(), obstacleGrid[0].size(), obstacleGrid, map);
    }
private:
    int uniquePaths(int currentRow, int currentColumn, int m, int n, vector<vector<int>>& obstacleGrid, unordered_map<string, int>&map){
        if(currentRow >= m || currentColumn >= n || obstacleGrid[currentRow][currentColumn] == 1 )
            return 0;
        
        if(currentRow == m-1 && currentColumn == n-1)
            return 1;
        
        string key = to_string(currentRow) + "_" + to_string(currentColumn);
        if(map.find(key) != map.end())
            return map[key];
        int moveRight = uniquePaths(currentRow, currentColumn + 1, m, n, obstacleGrid, map);
        int moveDown = uniquePaths(currentRow + 1, currentColumn, m, n, obstacleGrid, map);
        
        map[key] = moveRight + moveDown;
        return map[key];
    }
};