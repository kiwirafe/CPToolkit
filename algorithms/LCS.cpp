#include <bits/stdc++.h>
using namespace std;

void LCS(string line1, string line2) {
	int len1 = line1.size(), len2 = line2.size();
    int cur_val, pre_val;

    int dp[len2 + 1] = {0};
    for(int i = 1; i <= len1; i++) {
        pre_val = 0;
        for(int j = 1; j <= len2; j++) {
            cur_val = dp[j];
            dp[j] = max({dp[j], dp[j - 1], pre_val + (line1[i - 1] == line2[j - 1])});
            pre_val = cur_val;
        }
    }
    cout << dp[len2] << endl;
}

int main() {
    string line1 = "dynamic", line2 = "programming";
    LCS(line1, line2);
    return 0;
}