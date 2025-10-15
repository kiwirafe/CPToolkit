#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<int> adj[N];
int vis[N];

void dfs(int s) {
    if (vis[s]) return;
    vis[s] = true;
    // Process node s
    cout << s << endl;
    for (auto u: adj[s])
        dfs(u);

    // Add following line to explore all path (backtracking)
    // vis[s] = false;
}

int main() {
    // Adjacency List
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);

    dfs(0);
}