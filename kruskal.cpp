#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int root[N];

vector<pair<int, pair<int, int>>> edges;
vector<int> ans;

int find(int x) {
    if(root[x] == x) return x;
    root[x] = find(root[x]);
    return root[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    root[b] = a;
}

void kruskal(int noden) { // 0-indexed
    iota(begin(root), begin(root) + noden, 0);
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++) {
        int w = edges[i].first;
        int a = edges[i].second.first, b = edges[i].second.second;
        if(find(a) == find(b)) continue;
        ans.push_back(i);
        unite(a, b);
    }
}


int main() {
    edges.push_back({3, {1, 2}});
    edges.push_back({5, {1, 5}});
    edges.push_back({5, {2, 3}});
    edges.push_back({6, {2, 5}});
    edges.push_back({9, {3, 4}});
    edges.push_back({3, {3, 6}});
    edges.push_back({7, {4, 6}});
    edges.push_back({2, {5, 6}});

    kruskal(6);

    for (int i = 0; i < ans.size(); i++) {
        int x = edges[ans[i]].second.first, y = edges[ans[i]].second.second;
        cout << x << " " << y << endl;
    }
    return 0;
}
