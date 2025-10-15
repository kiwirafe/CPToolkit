#include <bits/stdc++.h>
using namespace std;

const int N = 10000;
int adj[N][N];
int dis[N][N];

void floydwarshall(int noden) {
    for (int i = 0; i < noden; i++) {
        for (int j = 0; j < noden; j++) {
            if (i == j) 
                dis[i][j] = 0;
            else if (adj[i][j]) 
                dis[i][j] = adj[i][j];
            else 
                dis[i][j] = INT_MAX / 4;
        }
    }

    for (int k = 0; k < noden; k++) {
        for (int i = 0; i < noden; i++) {
            for (int j = 0; j < noden; j++) {
                dis[i][j] = min(dis[i][j],
                    (dis[i][k] + dis[k][j]));
            }
        }
    }
}

int main() {
    // Adjacency Matrix with Weight
    adj[0][1] = 2;
    adj[0][2] = 4;
    adj[1][2] = 6;

    floydwarshall(3);
    cout << dis[0][2] << endl;
}