class Solution {
public:
    int numTrees(int n) {
        unordered_map<int, int> m;
        return uniqueBST(n, m);
    }
private:
    int uniqueBST(int n, unordered_map<int, int>&m){
        if(n == 0 || n == 1)
            return 1;
        
        int ways = 0;
        int key = n;
        if(m.find(key) != m.end())
            return m[key];
        
        for(int i = 0; i<= n-1; i++)
            ways += uniqueBST(i, m) * uniqueBST(n-i-1, m);
        
        m[key] = ways;
        return ways;
    }
};