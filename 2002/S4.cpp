#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <queue>
#include <cmath>
#include <climits>
#include <map>
#include <unordered_map>
#include <stack>
#include <ctime>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, N;
    cin >> M >> N;
    string name[N]; int time[N];
    for (int i = 0; i < N; i++) {
        cin >> name[i] >> time[i];
    }
    int dp[N + 1];
    int prev[N + 1];
    for (int i = 0; i <= N; i++) {
        dp[i] = INT_MAX;
        prev[i] = 0;
    }
    dp[0] = 0;
    prev[0] = -1;
    for (int i = 1; i <= N; i++) {
        int mx = 0;
        for (int j = 1; j <= min(M, i); j++) {
            mx = max(mx, time[i - j]);
            if (dp[i] > dp[i - j] + mx) {
                dp[i] = dp[i - j] + mx;
                prev[i] = i - j;
            }
        }
    }
    cout << "Total Time: " << dp[N] << '\n';
    vector<vector<string> > tot;
    int x = N;
    while (x != 0) {
        tot.emplace_back();
        for (int i = prev[x] + 1; i <= x; i++) {
            tot.back().push_back(name[i - 1]);
        }
        x = prev[x];
    }
    reverse(tot.begin(), tot.end());
    for (auto& p: tot) {
        for (string x: p) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}
