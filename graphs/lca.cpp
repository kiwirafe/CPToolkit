// Author: Ningyuan Yang
// It is OK to share my code for educational purposes

#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
typedef long long ll;

int n, l;
vector<vector<int>> adj;
int timer;
vector<int> tin, tout, depth;
vector<vector<int>> up;

// This uses LCA with Binary Lifting
// Code adapted from https://cp-algorithms.com/graph/lca_binary_lifting.html

// DFS to precompute ancestors
// Also calculates the depth of each node
void dfs(int v, int p) {
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];

    for (int u : adj[v]) {
        if (u != p) {
            depth[u] = depth[v] + 1;
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

// Check if u is ancestor of v
bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

// Find LCA of u and v
int lca(int u, int v) {
    if (is_ancestor(u, v)) 
        return u;
    if (is_ancestor(v, u)) 
        return v;
    for (int i = l; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

// Preprocess the tree and initlialize vectors
void preprocess(int root) {
    tin.resize(n + 1);
    tout.resize(n + 1);
    depth.resize(n + 1);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n + 1, vector<int>(l + 1));

    dfs(root, root);
}

// Return the distance between nodes a and b
int dist(int a, int b) {
    int c = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[c];
}

int main() {
    n = 7;

    adj.resize(n + 1);
    adj[1].push_back(2); adj[2].push_back(1);
    adj[1].push_back(3); adj[3].push_back(1);
    adj[2].push_back(4); adj[4].push_back(2);
    adj[2].push_back(5); adj[5].push_back(2);
    adj[3].push_back(6); adj[6].push_back(3);
    adj[3].push_back(7); adj[7].push_back(3);

    // Preprocess from root (node 1)
    preprocess(1);

    int a = 4, b = 7;
    cout << lca(2, 7) << endl;
    cout << dist(a, b) << endl;
    return 0;
}
