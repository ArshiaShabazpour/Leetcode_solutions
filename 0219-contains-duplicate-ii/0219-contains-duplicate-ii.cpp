class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> seen;
        if (nums.size()>7){
            sort(nums.begin() ,nums.end());
            for (int j=0;j<nums.size()-1;j++){
                if (nums[j]==nums[j+1])
                    return true;
            }
        }
        else{
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) {
                seen.erase(nums[i - k - 1]);
            }

            if (seen.find(nums[i]) != seen.end()) {
                return true;
            }

            seen.insert(nums[i]);
        }
        }

        return false;        
    }
};