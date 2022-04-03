class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
      unordered_map<int, int> m;
      return min(minCost(cost, 0, m) , minCost(cost, 1, m));
    }
    
private:
    int minCost(vector<int>& cost,int currentStair,unordered_map<int, int>&m){
        if(currentStair == cost.size())
            return 0;
        if(currentStair > cost.size())
            return 1001;
        
        int key = currentStair;
        if(m.find(key) != m.end())
            return m[key];
    int oneStep = cost[currentStair] + minCost(cost, currentStair+1, m);
    int twoStep = cost[currentStair] +  minCost(cost, currentStair+2, m);
        
       m[key] = min(oneStep, twoStep);
       return m[key];
    }
};