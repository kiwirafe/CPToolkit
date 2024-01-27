#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
vector<int> adj[N];
vector<int> ans;
int vis[N] = {0};
int flag = 0;

void dfs(int x) {
    if(vis[x] == 1) {
        flag = 1;
        return;
    }
    vis[x] = 1;
    for(auto u : adj[x]) {
        if(vis[u] == 2) continue;
        dfs(u);
    }
    vis[x] = 2;
    ans.push_back(x);
}

void topological_sort(int noden) {
    for(int i = 0; i < noden; i++) {
        if (vis[i]) continue;
        dfs(i);
    }

    if (flag)
        ans.clear();
    else
        reverse(ans.begin(), ans.end());
}

int main() {
    // Adjacency List with Weight
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(6);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(2);

    topological_sort(6);

    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}