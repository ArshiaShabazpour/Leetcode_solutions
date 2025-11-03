class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int ans = 0;
        int sum =neededTime[0];
        int max_num = neededTime[0];
        for(int i = 1;i<n;i++){
            if(colors[i] != colors[i-1]){
                ans += sum - max_num;
                sum = 0;
                max_num = 0;
            }
            max_num = max(neededTime[i],max_num);
            sum += neededTime[i];

        }
        ans += sum - max_num;
        return ans;
    }
};