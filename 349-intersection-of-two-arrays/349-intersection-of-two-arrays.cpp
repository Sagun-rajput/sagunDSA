class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool> m;
        for(auto i : nums1){
                m[i]=true;
        }
        vector<int> ans;
        for(auto j : nums2){
            if(m.find(j) != m.end() && m[j])
                ans.push_back(j);
                m[j]=false;
        }
        return ans;
    }
};