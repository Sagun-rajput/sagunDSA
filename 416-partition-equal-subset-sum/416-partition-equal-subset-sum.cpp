class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(auto i:nums)
            sum += i;
        if(sum %2 != 0)
            return false;
        unordered_map<string, int> m;
        return equalSubsetSum(nums, 0, sum/2, m);
    }
private:
    bool equalSubsetSum(vector<int>&nums, int CI, int total, unordered_map<string, int>& m){
        if(CI >= nums.size())
            return false;
        if(total == 0)
            return true;
        
        bool consider = false;
        string key = to_string(CI) + "_" + to_string(total);
        if(m.find(key) != m.end())
            return m[key];
        
        if(total >= nums[CI])
            consider = equalSubsetSum(nums, CI + 1, total - nums[CI], m);
            
        if(consider){
            m[key];
            return true;
        }
        bool notConsider = equalSubsetSum(nums, CI + 1, total, m);
            
        m[key] = (consider || notConsider);
        return m[key];
            
        
    }
};