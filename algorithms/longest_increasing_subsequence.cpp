#include <bits/stdc++.h>
using namespace std;

// Find the length of the longest increasing subsequence in an array
int longest_increasing_subsequence(const vector<int>& nums) {
    int l, r, len = 0;
    int tails[nums.size()];

    for (int i = 0; i < nums.size(); i++) {
        l = 0, r = len;
        // Binary Search
        while (l != r) {
            int m = (l + r) / 2;
            if (tails[m] < nums[i]) l = m + 1;
            else r = m;
        }
        tails[l] = nums[i]; 
        len = max(l + 1, len); 
    }	

    return len;
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int len = longest_increasing_subsequence(nums);

    return 0;
}