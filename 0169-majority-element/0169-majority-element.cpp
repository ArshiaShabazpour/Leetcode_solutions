class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mode = 0;
        int counter =0;
        for (int i = 0; i <nums.size(); i++){   
            if (counter == 0){
                mode = nums[i];
            }
            if( mode == nums[i]){
                counter++;
            }
            else{
                counter--;
            }
        }
         return mode;
    }
};