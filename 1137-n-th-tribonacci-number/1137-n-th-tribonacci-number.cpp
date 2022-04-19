class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int,int> m;
        return trib(n, m);
    }
private:
    int trib(int n, unordered_map<int,int>&m){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        int key = n;
        if(m.find(key) != m.end())
            return m[key];
        int tri = trib(n-1, m) + trib(n-2, m) + trib(n-3, m);
        
        m[key] = tri;
        return m[key];
            
    }
};