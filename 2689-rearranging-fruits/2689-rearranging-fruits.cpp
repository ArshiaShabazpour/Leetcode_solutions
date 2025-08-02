class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> freq, count1, count2;

        for (int num : basket1) {
            freq[num]++;
            count1[num]++;
        }
        for (int num : basket2) {
            freq[num]++;
            count2[num]++;
        }

        for (auto& [num, count] : freq) {
            if (count % 2 != 0) return -1;
        }

        vector<int> toSwap1, toSwap2;
        int minElem = INT_MAX;

        for (auto& [num, total] : freq) {
            int half = total / 2;
            int diff1 = count1[num] - half;
            int diff2 = count2[num] - half;

            if (diff1 > 0) {
                for (int i = 0; i < diff1; ++i)
                    toSwap1.push_back(num);
            }

            if (diff2 > 0) {
                for (int i = 0; i < diff2; ++i)
                    toSwap2.push_back(num);
            }

            minElem = min(minElem, num);
        }

        sort(toSwap1.begin(), toSwap1.end());
        sort(toSwap2.rbegin(), toSwap2.rend());  

        long long cost = 0;
        int n = toSwap1.size();
        for (int i = 0; i < n; ++i) {
            int a = toSwap1[i];
            int b = toSwap2[i];
            cost += min({a, b, 2 * minElem});
        }

        return cost;
    }
};
