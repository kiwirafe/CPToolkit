#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int tree[N];

int query(int a, int b, int n) {
	a += n, b += n;
	int ans = INT_MAX;
	while(a <= b) {
		if (a % 2 == 1) ans = min(ans, tree[a++]);
		if (b % 2 == 0) ans = min(ans, tree[b--]);
		a /= 2, b /= 2;
	}

	return ans;
}

void update(int pos, int val, int n) {
	pos += n;
	tree[pos] = val;

	for (pos /= 2; pos >= 1; pos /= 2) {
		tree[pos] = min(tree[2 * pos], tree[2 * pos + 1]);
	}
}

int main() {
    int n = 5;
	
	update(1, 2, n);
    update(2, 4, n);
    update(3, 6, n);
    update(4, 8, n);
    update(5, 10, n);

    query(1, 4, 5);
}