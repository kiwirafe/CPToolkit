#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<pair<int, int>> adj[N];
int dis[N];
bool vis[N];

void dfs(int s, int sum) {
    if (vis[s]) return;
    vis[s] = true;
    dis[s] = min(sum, dis[s]);
    // Process node s
    for (auto u: adj[s])
        dfs(u.first, (sum ^ u.second));

    vis[s] = false;
}

void shortest_xor_path(int noden, int source) {
    for (int i = 0; i < noden; i++) {
        dis[i] = INT_MAX;
    }

    dfs(source, 0);
}

int main() {
    // This calculates the shortest XOR path from source to dest
    adj[0].push_back({1, 1});
    adj[1].push_back({2, 2});
    adj[2].push_back({3, 4});

    shortest_xor_path(4, 0);
    cout << dis[3] << endl;
}