class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int num =1; 
        vector<int> leftsum;
        for(int i = 0; i <nums.size();i++){
            leftsum.push_back(num);
            num = num *nums[i];
        }
        num =1; 
        for(int i = nums.size()-1;i>-1; i--){
            int temp = nums[i];
            nums[i] = num;
            num = num *temp;
        }
        for(int i = 0; i <nums.size();i++){
            leftsum[i] = leftsum[i] * nums[i];
        }
        return leftsum;
    }
};