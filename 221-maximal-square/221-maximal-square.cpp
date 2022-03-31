class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        unordered_map<string, int> m;
        int area = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j<col; j++){
                if(matrix[i][j] == '1'){
                   int sideLength = maxSquare(matrix, i, j, row, col, m);
                   area = max(area, sideLength*sideLength);
                }
            }
        }
        return area;
    }
    private:
    int maxSquare(vector<vector<char>>&matrix, int CR, int CC, int row, int col, unordered_map<string, int>&m){
            if(CR < 0 || CC < 0 || CR >= row || CC >= col || matrix[CR][CC] == '0')
                return 0;
             
        string key = to_string(CR) + '_' + to_string(CC);
        if(m.find(key) != m.end())
            return m[key];
        
           int moveRight = 1 + maxSquare(matrix, CR, CC+1, row, col, m);
           int moveDown = 1 + maxSquare(matrix, CR+1, CC, row, col, m);
           int moveDiagonal = 1 + maxSquare(matrix, CR+1, CC+1, row, col, m);    
        m[key] = min(moveRight, min(moveDown, moveDiagonal));
        return m[key];
        }
};