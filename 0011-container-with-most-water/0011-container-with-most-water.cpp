class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1; 
        int max =0;
        while(left<right){
            if((right-left)*min(height[right],height[left]) > max){
                max = (right-left)*min(height[right],height[left]);
            }
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return max;
}
};