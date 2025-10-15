#include <bits/stdc++.h>
using namespace std;

// Find the maximum subarray sum using Kadane's algorithm
int max_subarray_sum(const vector<int>& nums) {
    int sum  = 0;
    int max_sum = 0;
    for (int num : nums) {
        sum = max(num, sum + num); // Either extend the previous subarray or start new at x
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}

int main() {
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    max_subarray_sum(nums);
}