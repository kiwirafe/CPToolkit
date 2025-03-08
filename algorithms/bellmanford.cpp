#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<pair<int, pair<int, int>>> edges;
int dis[N];

void bellmanford(int noden) {
    for (int i = 0; i < noden; i++) dis[i] = INT_MAX / 4;

    dis[0] = 0;
    for (int i = 0; i < noden - 1; i++) {
        for (auto e : edges) {
            int a = e.second.first;
            int b = e.second.second;
            int w = e.first;
            dis[b] = min(dis[b], dis[a] + w);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    bellmanford(n);

    return 0;
}