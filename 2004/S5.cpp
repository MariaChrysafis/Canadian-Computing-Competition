#include <bits/stdc++.h>

using namespace std;
string grid[100];
int dp[100][100][2][2];
int n, m;
int rec (int x, int y, bool a, bool b) {
    int val = max(grid[x][y] - '0', 0);
    if (dp[x][y][a][b] != -INT_MAX) {
        return dp[x][y][a][b];
    }
    if (b && x != 0 && grid[x - 1][y] != '*') {
        dp[x][y][a][b] = max(dp[x][y][a][b], rec(x - 1, y, false, true) + val);
    }
    if (a && x != n - 1 && grid[x + 1][y] != '*') {
        dp[x][y][a][b] = max(dp[x][y][a][b], rec(x + 1, y, true, false) + val);
    }
    if (y != m - 1 && grid[x][y + 1] != '*') {
        dp[x][y][a][b] = max(dp[x][y][a][b], rec(x, y + 1, true, true) + val);
    }
    return dp[x][y][a][b];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while (n != 0 && m != 0) {
        for (int i = 0; i < n; i++) {
            cin >> grid[i];
        }
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        dp[i][j][x][y] = -INT_MAX;
                    }
                }
            }
        }
        int x = n -1 , y = m - 1;
        dp[n - 1][m - 1][0][0] = dp[n - 1][m - 1][0][1] = dp[n - 1][m - 1][1][0] = dp[n - 1][m - 1][1][1] = ((grid[x][y] >= '0' && grid[x][y] <= '9') ? grid[x][y] - '0' : ((grid[x][y] == '*') ? -1 : 0));
        cout << rec(n - 1, 0, true, true) << '\n';
        cin >> n >> m;
    }
}
