#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &nums, int l, int mid, int r) {
	int i = l, j = mid + 1, k = 0, size = r - l + 1;
	vector<int> sorted(size, 0);
    int count_inv = 0;

	while (i <= mid && j <= r) {
        if (nums[i] <= nums[j]) {
            sorted[k++] = nums[i++];
        } else {
            // nums[i] > nums[j] → every element from i..mid is > nums[j]
            count_inv += (mid - i + 1);
            sorted[k++] = nums[j++];
        }
    }

	while (i <= mid) // Copy remaining elements from left half
		sorted[k++] = nums[i++];
	while (j <= r) // Copy remaining elements from right half
		sorted[k++] = nums[j++]; 
	for (k = 0; k < size; k++) // Copy back to original array
		nums[k + l] = sorted[k];

    return count_inv;
}

int count_inversions(vector<int> &nums, int l, int r) {
	if (l >= r) return 0;
	int mid = (r - l) / 2 + l;

	int left_inv = count_inversions(nums, l, mid);
	int right_inv = count_inversions(nums, mid + 1, r);
	int merge_inv = merge(nums, l, mid, r);

    return left_inv + right_inv + merge_inv;
}

int main() {
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    count_inversions(nums, 0, nums.size() - 1);
	return 0;
}