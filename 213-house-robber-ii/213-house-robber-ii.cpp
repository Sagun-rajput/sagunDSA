class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        unordered_map<int, int>m1;
        unordered_map<int, int>m2;
        if(len == 1)
            return nums[0];
        return max(houseRobber2(0, len-1, nums, m1), houseRobber2(1, len, nums, m2));
    }
private:
    int houseRobber2(int CI, int target, vector<int>&nums, unordered_map<int, int>&m){
        if(CI >= target)
            return 0;
        int key = CI;
        if(m.find(key) != m.end())
            return m[key];
        int rob = nums[CI] + houseRobber2(CI+2, target, nums, m);
        int dontRob = houseRobber2(CI+1, target, nums, m);
        
        m[key] = max(rob, dontRob);
        return m[key];
    }
};