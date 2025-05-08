class Solution {
public:
    void backtrack(const vector<int>& nums, 
                   vector<int>& rest_nums, vector<int>& path, vector<vector<int>>& permutations){
        for(int i=0; i<rest_nums.size(); ++i){
            int val = rest_nums[i];
            rest_nums.erase(rest_nums.begin() + i);
            path.push_back(val);
            if(path.size() == nums.size())
            {
                permutations.push_back(path);
            }
            else
            {
                backtrack(nums, rest_nums, path, permutations);
            }
            path.pop_back();
            rest_nums.insert(rest_nums.begin() + i, val);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;

        vector<int> rest_nums = nums;
        vector<int> path;
        backtrack(nums, rest_nums, path, permutations);

        return permutations;
    }
};