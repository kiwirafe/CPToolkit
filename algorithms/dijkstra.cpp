#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<pair<int, int>> adj[N];
int dis[N];
bool vis[N];

void dijkstra(int source) {
    for(int i = 0; i < N; i++){
        dis[i] = INT_MAX;
        vis[i] = false;
    }

    priority_queue<pair<int, int>> q;
    dis[source] = 0;
    q.push({0, source});
    while(!q.empty()) {
        int a = q.top().second; q.pop();
        if(vis[a]) continue;
        vis[a] = true;
        for(auto u : adj[a]) {
            int b = u.first; int w = u.second;
            if (dis[a] + w < dis[b]) {
                dis[b] = dis[a] + w;
                q.push({-dis[b], b});
            }
        }
    }
}

int main() {
    // Adjacency List with Weight
    adj[0].push_back({1, 2});
    adj[0].push_back({2, 4});
    adj[1].push_back({2, 6});

    dijkstra(0);
    cout << dis[2] << endl;
}