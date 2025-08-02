class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int  ma=*max_element(nums.begin(),nums.end());
        int cnt=0;
        int ans=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==ma)
            {
                cnt++;
                ans=max(ans,cnt);
            }
            else cnt=0;


        }
        return ans;

    }
};