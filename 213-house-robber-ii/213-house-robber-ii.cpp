class Solution {
public:
     int rob(vector<int>& nums) {
        unordered_map<int, int> m;
        unordered_map<int, int> m1;
         
        int len = nums.size();
         if(len==1)
             return nums[0];
        
        return max(robber(nums, 0, len-1, m), robber(nums, 1, len, m1));
    }
    
private:
    int robber(vector<int>& nums, int CI, int target, unordered_map<int, int>& m){
        if(CI >= target)
            return 0;
        
        int key = CI;
        if(m.find(key) != m.end())
            return m[key];
        
        int rob = nums[CI] + robber(nums, CI+2, target, m);
        int noRob = robber(nums, CI+1, target, m);
        
        m[key] = max(rob, noRob);
        return m[key];
    }
};
