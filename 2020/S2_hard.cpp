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
bool can_escape (int N, int M, vector<vector<int> > arr) {
    int cnt[N * M + 1];
    for (int i = 0; i <= N * M; i++) {
        cnt[i] = 0; //cnt is number of guys in each row
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i + 1][j + 1] <= N * M) {
                cnt[(i + 1) * (j + 1) - 1]++;
            }
        }
    }
    int ptr[N * M + 1];
    for (int i = 1; i <= N * M; i++) {
        cnt[i] += cnt[i - 1];
    }
    ptr[0] = 0;
    for (int i = 1; i <= N * M; i++) {
        ptr[i] = cnt[i - 1];
    }
    int c[cnt[N * M]];
    for (int i = 0; i < cnt[N * M]; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i + 1][j + 1] <= N * M) {
                c[ptr[(i + 1) * (j + 1) - 1]++] = arr[i + 1][j + 1] - 1;
            }
        }
    }
    bool vis[N * M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            vis[M * i + j] = false;
        }
    }
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        int left = (x == 0 ? 0: cnt[x - 1]);
        assert(left <= cnt[x]);
        for (int i = left; i < cnt[x]; i++) {
            int val = c[i];
            if (!vis[val]) {
                vis[val] = true;
                q.push(val);
            }
        }
    }
    return vis[N * M - 1];
}
