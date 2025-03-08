#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<int> adj[N];
int dis[N];
bool vis[N];

void bfs(int x) {
    vis[x] = true;
    dis[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int s = q.front(); q.pop();
        // Process node s
        cout << s << endl;
        for (auto u : adj[s]) {
            if (vis[u]) 
                continue;
            vis[u] = true;
            dis[u] = dis[s] + 1;
            q.push(u);
        }
    }
}

int main() {
    // Adjacency List
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(2);

    bfs(0);
}