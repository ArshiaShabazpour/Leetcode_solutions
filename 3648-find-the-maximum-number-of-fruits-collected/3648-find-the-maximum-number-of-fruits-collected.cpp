#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& a) {
        int n = (int)a.size();
        if (n == 0) return 0;

        // Add the diagonal once (kid A is forced along it).
        long long base = 0;
        for (int t = 0; t < n; ++t) base += a[t][t];

        const long long NEG = LLONG_MIN / 4;

        // -------- Kid B (starts (0, n-1), moves down each step, col changes -1/0/+1) --------
        // dpB[j] = best total for B at step t at column j
        vector<long long> dpB(n, NEG), nxtB(n, NEG);
        // t = 0: B at (0, n-1)
        dpB[n - 1] = 0 + (/*zero-out diagonal*/ ((n - 1 == 0) ? 0 : a[0][n - 1]));

        for (int t = 1; t < n; ++t) {
            fill(nxtB.begin(), nxtB.end(), NEG);
            for (int j = 0; j < n; ++j) if (dpB[j] != NEG) {
                for (int dj : {-1, 0, 1}) {
                    int nj = j + dj;
                    if (0 <= nj && nj < n) {
                        long long gain = (nj == t) ? 0 : a[t][nj]; // zero if diagonal
                        nxtB[nj] = max(nxtB[nj], dpB[j] + gain);
                    }
                }
            }
            dpB.swap(nxtB);
        }
        // must end at (n-1, n-1) -> column n-1
        long long bestB = dpB[n - 1];

        // -------- Kid C (starts (n-1, 0), moves right each step, row changes -1/0/+1) --------
        // dpC[i] = best total for C at step t at row i
        vector<long long> dpC(n, NEG), nxtC(n, NEG);
        // t = 0: C at (n-1, 0)
        dpC[n - 1] = 0 + (/*zero-out diagonal*/ ((n - 1 == 0) ? 0 : a[n - 1][0]));

        for (int t = 1; t < n; ++t) {
            fill(nxtC.begin(), nxtC.end(), NEG);
            for (int i = 0; i < n; ++i) if (dpC[i] != NEG) {
                for (int di : {-1, 0, 1}) {
                    int ni = i + di;
                    if (0 <= ni && ni < n) {
                        long long gain = (ni == t) ? 0 : a[ni][t]; // zero if diagonal
                        nxtC[ni] = max(nxtC[ni], dpC[i] + gain);
                    }
                }
            }
            dpC.swap(nxtC);
        }
        // must end at (n-1, n-1) -> row n-1
        long long bestC = dpC[n - 1];

        // Total = diagonal once + best for B (no diagonal counted there) + best for C (no diagonal counted there)
        return (int)(base + max(0LL, bestB) + max(0LL, bestC));
    }
};
