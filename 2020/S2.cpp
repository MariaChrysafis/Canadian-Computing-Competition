#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <queue>
#include <cmath>
#include <numeric>
#include <functional>
#include <climits>
#include <map>
#include <unordered_map>
#include <stack>
#include <ctime>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> adj[N * M];
    int arr[N + 1][M + 1];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i + 1][j + 1];
            if (arr[i + 1][j + 1] <= N * M) {
                adj[arr[i + 1][j + 1] - 1].push_back(M * i + j + N * M); //index to product of indices
            }
        }
    }
    bool vis[2 * N * M];
    for (int i = 0; i < 2 * N * M; i++) {
        vis[i] = false;
    }
    queue<int> q;
    q.push(2 * N * M - 1);
    vis[2 * N * M - 1] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x >= N * M) {
            x -= N * M;
            int new_guy = (x/M + 1) * (x % M + 1) - 1;
            if (!vis[new_guy]) {
                q.push(new_guy);
                vis[new_guy] = true;
            }
        } else {
            for (int i: adj[x]) {
                if (!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
    }
    cout << (vis[N * M] ? "yes" : "no");
}
