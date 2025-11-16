#include <bits/stdc++.h>
using namespace std;

// Return maximum obtainable value from a rod of length n
int rod_cutting(const vector<int>& prices, int n) {
    vector<int> dp(n + 1, 0); // dp[i] = best price for rod length i

    for (int i = 1; i <= n; i++) {
        for (int cut = 1; cut <= i; cut++)
            dp[i] = max(dp[i], prices[cut - 1] + dp[i - cut]);
    }

    return dp[n];
}

int main() {
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    rod_cutting(prices, 8);
}
