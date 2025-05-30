class Solution {
public:
    vector<vector<int>> kSmallestPairs(
        vector<int>& nums1,
        vector<int>& nums2,
        int k
    ) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return res;

        int n1 = nums1.size(), n2 = nums2.size();
        using T = tuple<int,int,int>;
        auto cmp = [](const T &a, const T &b) {
            return get<0>(a) > get<0>(b);
        };
        priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < n1 && i < k; ++i) {
            pq.emplace(nums1[i] + nums2[0], i, 0);
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            res.push_back({ nums1[i], nums2[j] });
            if (j + 1 < n2) {
                pq.emplace(nums1[i] + nums2[j+1], i, j+1);
            }
        }

        return res;
    }
};
