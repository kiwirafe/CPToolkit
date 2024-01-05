#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int root[N];
int height[N];

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
    if (height[a] < height[b]) swap(a, b);
    height[a] += height[b];
    root[b] = a;
}

void kruskal(int noden) {
    for(int i = 1; i <= noden; i++) {
        root[i] = i;
        height[i] = 1;
    }
    
    sort(edges.begin(), edges.end());
    for(int i = 0; i < edges.size(); i++) {
        int w = edges[i].first;
        int x = edges[i].second.first, y = edges[i].second.second;
        if(find(x) == find(y)) continue;
        ans.push_back(i);
        unite(x, y);
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
