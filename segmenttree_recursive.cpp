#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
int tree[N] = {INT_MIN};

void update(int pos, int val, int n, int tl, int tr) {
    if (tl == tr) {
        tree[n] = val;
        return;
    }

    int tm = (tl + tr) / 2;
    if (pos <= tm) update(pos, val, n * 2, tl, tm);
    else update(pos, val, n * 2 + 1, tm + 1, tr);
    tree[n] = max(tree[n * 2], tree[n * 2 + 1]);
}

int query(int l, int r, int n, int tl, int tr) {
    if (l <= tl and tr <= r) {
        return tl;
    }
    int tm = (tl + tr) / 2;
    int ans = INT_MIN;
    if (l <= tm) ans = max(ans, query(l, r, n * 2 + 1, tm + 1, tr));
    if (tm < r) ans = max(ans, query(l, r, n * 2, tl, tm));

    return ans;
}

int main() {
    int n = 5;

	update(1, 2, 5, 1, n);
    update(2, 4, 5, 1, n);
    update(3, 6, 5, 1, n);
    update(4, 8, 5, 1, n);
    update(5, 10, 5, 1, n);

    query(1, 4, 5, 1, n);
}