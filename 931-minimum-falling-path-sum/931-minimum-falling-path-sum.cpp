class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int ans = 1000001;
        unordered_map<string, int> m;
            for(int j = 0; j< col; j++){
                int tempAns = minFallingSum(matrix, 0, j, row, col, m);
                ans = min(ans, tempAns);
            }
        return ans;
}
        
private: 
        int minFallingSum(vector<vector<int>>& matrix,int currentRow, int currentCol, int row, int col, unordered_map<string, int>&m){
            if(currentCol < 0 || currentCol >= col)
                return 1000001;
            
            if(currentRow == row-1)
                return matrix[currentRow][currentCol];
            
    string key = to_string(currentRow) + "_" + to_string(currentCol);
    if(m.find(key) != m.end())
        return m[key];
            
    int leftDiagonal = matrix[currentRow][currentCol] + minFallingSum(matrix, currentRow + 1, currentCol-1, row, col, m);
    int down = matrix[currentRow][currentCol] + minFallingSum(matrix, currentRow + 1, currentCol, row, col, m);
    int rightDiagonal = matrix[currentRow][currentCol] + minFallingSum(matrix, currentRow + 1, currentCol+1, row, col, m);
            
    m[key] = min(leftDiagonal, min(down, rightDiagonal));
    return m[key];
    }
};