class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, bool>m;
        // traversing nums1 and entering values in map m
        for(auto i : nums1)
            m[i] = true;
        // initialisng a new array
        vector<int> arr; 
         // traversing through nums2 and matching the value
        for(auto j:nums2){
            if(m.find(j) != m.end()){
                arr.push_back(j);
                 m.erase(j);
            }
        }
        
        return arr;
    }
};