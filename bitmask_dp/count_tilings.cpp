#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int count_tilings(int n, int m) {
    vector<vector<int>> dp(1 << n, vector<int>(2, 0));

    dp[0][0] = 1;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int mask = 0; mask < (1 << n); mask++) {
                dp[mask][1] = dp[mask ^ (1 << i)][0];

                if (i > 0 && !(mask & (1 << i)) && !(mask & (1 << (i - 1))))
                    dp[mask][1] += dp[mask ^ (1 << (i - 1))][0];
                
                if (dp[mask][1] >= MOD) 
                    dp[mask][1] -= MOD;
            }

            for (int mask = 0; mask < (1 << n); mask++)
                dp[mask][0] = dp[mask][1];
        }
    }

    return dp[0][0];
}

int main() {
    int n = 4, m = 6;
    cout << count_tilings(n, m) << endl;
}