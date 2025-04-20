class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int right = 0;
        int sum = nums[0];
        int size = 0; 
        if(sum>target){
            return 1;
        }
        for(int left = 1; left <nums.size(); left++){
            if(sum>=target){
                if(size !=0){
                    size = min(size,left-right+1);
                }
                else{
                    size = left-right+1;
                }
            }
            sum += nums[left];
            while(sum- nums[right]>=target){
                sum = sum- nums[right];
                right++;
            }
            if(sum>=target){

                if(size !=0){
                    size = min(size,left-right+1);
                }
                else{
                    size = left-right+1;
                }
            }
        }
    
        return size;
    }
};