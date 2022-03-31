class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        unordered_map<string, int> m;
        return diceRollsWithTargetSum(n, k, target, m);
    }
private:
    int diceRollsWithTargetSum(int n, int f, int TS, unordered_map<string, int>&m){
       
        if(n == 0 && TS == 0)
            return 1;
        
         if(n == 0 && TS != 0)
            return 0;
        string key = to_string(n) + '_' + to_string(TS);
        if(m.find(key) != m.end())
            return m[key];
        int ways = 0;
        int MOD = 1000000007;
        // (a+b) % MOD = (a % MOD +b % MOD) % MOD
        for(int i = 1; i <= f; i++){
           int tempways = (diceRollsWithTargetSum(n-1, f, TS-i, m)) % MOD;
            ways = ways % MOD;
            ways = (tempways + ways) % MOD;
        }
        
        m[key] = ways;
        return m[key];
    } 
};