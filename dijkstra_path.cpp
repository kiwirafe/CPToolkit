#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<pair<int, int>> adj[N];
int dis[N];
bool vis[N];
int pre[N];

void dijkstra(int source) {
    for(int i = 0; i < N; i++){
        dis[i] = INT_MAX;
        vis[i] = false;
        pre[i] = -1;
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
                pre[b] = a;
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

    vector<int> path;
    int current = 2;
    while (current != -1) {
        path.push_back(current);
        current = pre[current];
    }
    
    reverse(path.begin(), path.end());
}