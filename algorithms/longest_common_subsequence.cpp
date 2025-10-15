#include <bits/stdc++.h>
using namespace std;

// Find the length of the longest common substring between two strings
int longest_common_subsequence(const string& line1, const string& line2) {
	int n = line1.size(), m = line2.size();
    vector<int> dp(m + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int prev = 0;
        for (int j = 1; j <= m; ++j) {
            int cur = dp[j];
            if (line1[i - 1] == line2[j - 1]) 
                dp[j] = prev + 1;
            else 
                dp[j] = max(dp[j], dp[j - 1]);
            
            prev = cur;
        }
    }
    return dp[m];
}

int main() {
    string line1 = "dynamic", line2 = "programming";
    longest_common_subsequence(line1, line2);
    return 0;
}