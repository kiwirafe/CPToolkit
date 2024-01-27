#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<pair<int, pair<int, int>>> edges;
int dis[N];

bool bellmanford(int noden) {
    for (int i = 0; i <= noden; i++) dis[i] = INT_MAX / 4;

    dis[0] = 0;
    for (int i = 0; i <= noden; i++) {
        for (auto e : edges) {
            int a = e.second.first;
            int b = e.second.second;
            int w = e.first;

            if (i == noden and dis[a] + w < dis[b]) {
                return true;
            } else {
                dis[b] = min(dis[b], dis[a] + w);
            }
        }
    }
    
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    int a, b, w;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    bool negative_cycle = bellmanford(n);

    return 0;
}