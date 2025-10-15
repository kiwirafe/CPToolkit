#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int l, int mid, int r) {
	int i = l, j = mid + 1, k = 0, size = r - l + 1;
	vector<int> sorted(size, 0);

	while (i <= mid and j <= r) // Merge two sorted halves
		sorted[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
	while (i <= mid) // Copy remaining elements from left half
		sorted[k++] = nums[i++];
	while (j <= r) // Copy remaining elements from right half
		sorted[k++] = nums[j++]; 
	for (k = 0; k < size; k++) // Copy back to original array
		nums[k + l] = sorted[k];
}

void merge_sort(vector<int> &nums, int l, int r) {
	if (l >= r) return;
	int mid = (r - l) / 2 + l;

    // Sort both halves
	merge_sort(nums, l, mid);
	merge_sort(nums, mid + 1, r);

    // Merge both halves
	merge(nums, l, mid, r);
}

int main() {
    vector<int> nums = {38, 27, 43, 3, 9, 82, 10};
    merge_sort(nums, 0, nums.size() - 1);
	return 0;
}