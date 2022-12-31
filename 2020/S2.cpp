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
struct graph{
    const int inf = 1e8;
    vector<vector<pair<int,int>>> adj; //{-weight, node}
    vector<int> dijk(int src){
        vector<int> dist;
        vector<bool> mark;
        dist.resize(adj.size()), mark.resize(adj.size());
        for(int i = 0; i < adj.size(); i++){
            dist[i] = inf;
            mark[i] = false;
        }
        dist[src] = 0;
        priority_queue<pair<int,int>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int u = pq.top().second; //node
            pq.pop();
            if(mark[u]){
                continue;
            }
            mark[u] = true;
            for(auto p: adj[u]){
                int v = p.second;
                int w = p.first;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }
        return dist;
    }
};
int gcd (int x, int y) {
    return (min(x, y) == 0 ? max(x, y) : gcd(max(x, y) % min(x, y), min(x, y)));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    int arr[N + 1][M + 1];
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> arr[i][j];
        }
    }
    vector<pair<int,int>> fact[N * M + 1];
    for (int i = 1; i <= N; i++) {
        for (int f = i; f <= N * M; f += i) {
            if (f % i == 0 && f/i <= M && i <= N) {
                fact[f].emplace_back(i, f/i);
            }
        }
    }
    graph gr;
    gr.adj.resize(N * M);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (arr[i][j] > N * M) {
                continue;
            }
            for (auto& p: fact[arr[i][j]]) {
                gr.adj[M * i + j - M - 1].emplace_back(1, M * p.first + p.second - M - 1);
            }
        }
    }
    auto dum = gr.dijk(0);
    cout << ((dum[N * M - 1] == gr.inf) ? "no" : "yes") << '\n';
}
