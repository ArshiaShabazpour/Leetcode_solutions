#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;

        int start = 0;  
        int end = nums[0];  
        int maxReach = 0;  
        int counter = 1;  

        for (int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, i + nums[i]); 
            
            if (i == end) { 
                start = end; 
                counter++;
                end = maxReach; 
                
                if (end >= nums.size() - 1) break; 
            }
        }
        return counter;
    }
};
