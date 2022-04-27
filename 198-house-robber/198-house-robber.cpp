class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> m;
        return houseRobber(0, nums, m);
    }
private:
    int houseRobber(int CH, vector<int>&nums, unordered_map<int, int>&m){
        if(CH >= nums.size())
            return 0;
        int key = CH;
        if(m.find(key) != m.end())
            return m[key];
        int rob = nums[CH] + houseRobber(CH+2, nums, m);
        int dontRob = houseRobber(CH+1, nums, m);
        
        m[key] = max(rob, dontRob);
        return m[key]; 
    }
};