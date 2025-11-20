class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int>& X, vector<int>& Y){ 
            const int x0=X[0], x1=X[1], y0=Y[0], y1=Y[1]; 
            return (x1==y1)?x0>y0:x1<y1; 
        });
        int start = -1;
        int end = -1;
        int count = 0;
        for (const vector<int>& interval : intervals) {
            int left = interval[0];
            int right = interval[1];
            if (left > end) {
                start = right - 1;
                end = right;
                count += 2;
            } else if (left > start) {
                start = end;
                end = right;
                count += 1;
            }
        }
        return count;
    }
};