class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> v(2);
        v[0] = arr[0][0]; 
        v[1] = arr[0][1];
        int i = 1;
        while (i < n) {
            if (v[1] >= arr[i][0]) {
                v[1] = max(v[1], arr[i][1]);
            } else {
                ans.push_back(v);
                v[0] = arr[i][0];
                v[1] = arr[i][1];
            }
            i++;
        }
        ans.push_back(v);
        return ans;
    }
};