class Solution {
public:
    int uniquePaths(int m, int n) {
        unordered_map<string,int> map;
        return uniquePaths(0, 0, m, n, map);
    }
private:
    int uniquePaths(int currentRow, int currentColumn, int m, int n, unordered_map<string, int>&map){
        if(currentRow >= m || currentColumn >= n)
            return 0;
        
        if(currentRow == m-1 && currentColumn == n-1)
            return 1;
        
        string key = to_string(currentRow) + "_" + to_string(currentColumn);
        if(map.find(key) != map.end())
            return map[key];
        int moveRight = uniquePaths(currentRow, currentColumn + 1, m, n, map);
        int moveDown = uniquePaths(currentRow + 1, currentColumn, m, n, map);
        
        map[key] = moveRight + moveDown;
        return map[key];
    }
};