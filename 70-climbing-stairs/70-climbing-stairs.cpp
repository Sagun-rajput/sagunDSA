class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int, int>m;
       return distinctWaysToClimb(0, n, m);
    } 

private:
    int distinctWaysToClimb(int currentStair, int targetStair, unordered_map<int, int>&m){
        if(currentStair == targetStair)
            return 1;
        if(currentStair > targetStair)
            return 0;
        
        int key = currentStair;
        if(m.find(key) != m.end())
            return m[key];
        
        int oneStep = distinctWaysToClimb(currentStair + 1, targetStair, m);
        int twoStep = distinctWaysToClimb(currentStair + 2, targetStair, m);
        
        m[key] = oneStep + twoStep;
        return m[key];
    }
};