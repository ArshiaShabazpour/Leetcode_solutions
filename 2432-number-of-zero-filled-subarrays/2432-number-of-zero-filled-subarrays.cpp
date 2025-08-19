class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0; 
        long long counter = 0; 

        for (int num : nums) {
            if (num == 0) {
                counter++;
            } else {
                if (counter > 0) {
                    total += (counter * (counter + 1)) / 2; 
                }
                counter = 0; 
            }
        }

        if (counter > 0) {
            total += (counter * (counter + 1)) / 2;
        }

        return total;
    }
};
