class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool>m;
        for(auto i : nums1)
            m[i] = true;
        vector<int> arr;
        for(auto j:nums2){
            if(m.find(j) != m.end() &&  m[j]){
                arr.push_back(j);
                 m[j]= false;
            }
        }
        
        return arr;
    }
};