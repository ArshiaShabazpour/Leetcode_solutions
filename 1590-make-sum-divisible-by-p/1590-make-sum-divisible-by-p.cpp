class Solution {
public:
       int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        unordered_map<int, int> prefx;
        prefx[0] = -1;
        long long sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum < p) return -1; 

        int len = INT_MAX;
        int extra = sum%p;
        long long cumsum = 0;
        for(int i=0; i<n; i++){
            cumsum += nums[i];
            prefx[cumsum%p] = i;
            if(prefx.find((cumsum-extra+p)%p) != prefx.end()){
                int idx1 = prefx[(cumsum-extra+p)%p];
                len = min(len, i-idx1);
            }
        }
        if(len==INT_MAX || len==n) return -1;
        return len;
    }
};