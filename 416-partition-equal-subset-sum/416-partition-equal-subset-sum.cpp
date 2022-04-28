class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        unordered_map<string, int>m;
        for(auto i : nums)
            sum+=i;
        if(sum%2 != 0)
            return false;
        return answer(0, sum/2, nums, m);
    }
private:
    bool answer(int CI, int W, vector<int>&nums, unordered_map<string, int> &m){
        if(CI>=nums.size()) return false;
        if(W == 0) return true;
        bool canPick = false;
        string key = to_string(CI) + "_" + to_string(W);
        if(m.find(key) != m.end())
            return m[key];
        if(W >= nums[CI])
            canPick = answer(CI+1, W-nums[CI], nums, m);
        if(canPick) return true;
        bool cantPick = answer(CI+1, W, nums, m);
        m[key] = (canPick || cantPick);
        return m[key];
    }
};