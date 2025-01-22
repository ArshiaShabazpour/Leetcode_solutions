class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            for (int i = 0; i < n; i++) {
                nums1[i] = nums2[i];
            }
        } 
        else if (n == 0) {

        } 
        else {
            int slider = 0;
            for (int i = 0; i < m + n; i++) {
                if (slider >= n) {
                    break;
                }
                if (nums1[i] > nums2[slider] && i < m + slider) {
                    for (int j = m + slider; j > i; j--) {
                        nums1[j] = nums1[j - 1];
                    }
                    nums1[i] = nums2[slider];
                    slider++;
                } 
                else if (i >= m + slider) {
                    nums1[i] = nums2[slider];
                    slider++;
                }
            }
        }
    }
};
