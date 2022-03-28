class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        unordered_map<string, int> map;
        return minPathCost(0, 0, grid, map);
    }
private:
    int minPathCost(int currentRow, int currentColumn, vector<vector<int>>& grid,  unordered_map<string,int>&map){
        int m = grid.size();
        int n = grid[0].size();
        if(currentRow >= m || currentColumn >= n)
            return 10001;
        if(currentRow ==  m-1 && currentColumn == n-1)
            return grid[currentRow][currentColumn];
        
    string key = to_string(currentRow) + "_" + to_string(currentColumn);
    if(map.find(key) != map.end())
        return map[key];
        
    int moveRight = grid[currentRow][currentColumn] + minPathCost(currentRow, currentColumn+1, grid, map);
    int moveDown = grid[currentRow][currentColumn] + minPathCost(currentRow+1, currentColumn, grid, map);
        
        map[key] = min(moveRight, moveDown);
        return map[key];
    }
};