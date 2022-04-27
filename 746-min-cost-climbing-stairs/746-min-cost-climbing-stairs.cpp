class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      unordered_map<int, int> m;
      return min(minCost(0, cost, m), minCost(1, cost, m));
    }
private:
    int minCost(int CI, vector<int>& cost, unordered_map<int, int>&m){
        if(CI >= cost.size())
            return 0;
        int key = CI;
        if(m.find(key) !=m.end())
            return m[key];
        int oneStep = cost[CI] + minCost(CI+1, cost, m);
        int twoSteps = cost[CI] + minCost(CI+2, cost, m);
        
        m[key] = min(oneStep, twoSteps);
        return m[key];
    }
};