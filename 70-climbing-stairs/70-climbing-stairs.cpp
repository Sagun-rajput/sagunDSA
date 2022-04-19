class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int> m;
        return distinctWays(0, n, m);
    }
private:
    int distinctWays(int CI, int TS, unordered_map<int, int> &m){
        if(CI == TS) return 1;
        if(CI > TS) return 0;
    int key = CI;
    if(m.find(key) != m.end())
        return m[key];
        
    int oneStep = distinctWays(CI+1, TS, m);
    int twoSteps = distinctWays(CI+2, TS, m);
    
    m[key] = oneStep + twoSteps;
    return m[key];
    }
};