#include <bits/stdc++.h>
using namespace std;

// Find the maximum sum of elements in an array with the constraint that
// no more than n consecutive elements can be chosen.
int max_consecutive_elements(const vector<int>& nums, int n) {
    vector<int> dp(n, 0); // dp[k] = best sum ending with k consecutive picks

    for (int num : nums) {
        int prev = *max_element(dp.begin(), dp.end()); 
        for (int k = n - 1; k >= 1; k--)
            dp[k] = dp[k - 1] + num;
        dp[0] = prev;
    }

    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    max_consecutive_elements(nums, 4); // Output the result
}