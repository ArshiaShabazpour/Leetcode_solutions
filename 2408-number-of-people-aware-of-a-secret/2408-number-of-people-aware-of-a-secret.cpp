#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1'000'000'007;
        vector<vector<int>> mat(n, vector<int>(forget, 0));
        mat[0][0] = 1; 

        auto addmod = [&](long long a, long long b){ return int((a + b) % MOD); };

        for (int i = 1; i < n; ++i) {
            long long s = 0;
            int L = delay - 1;
            int R = forget - 2;
            if (L <= R) {
                for (int j = max(0, L); j <= min(forget - 1, R); ++j) {
                    s += mat[i - 1][j];
                    if (s >= MOD) s -= MOD;
                }
            }
            mat[i][0] = int(s % MOD);

            for (int j = 1; j < forget; ++j) {
                mat[i][j] = mat[i - 1][j - 1];
            }
        }

        long long ans = 0;
        for (int j = 0; j < forget; ++j) {
            ans += mat[n - 1][j];
            if (ans >= MOD) ans -= MOD;
        }
        return int(ans % MOD);
    }
};
