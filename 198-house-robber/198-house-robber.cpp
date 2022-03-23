class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> m;
        return robber(nums, 0, m);
    }
    
private:
    int robber(vector<int>& nums, int CI, unordered_map<int, int>& m){
        if(CI>= nums.size())
            return 0;
        
        int key = CI;
        if(m.find(key) != m.end())
            return m[key];
        
        int rob = nums[CI] + robber(nums, CI+2, m);
        int noRob = robber(nums, CI+1, m);
        
        m[key] = max(rob, noRob);
        return m[key];
    }
};