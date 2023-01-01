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
map<int64_t,int64_t> dp;
const int MX = 100000;
int64_t tot[MX];
int64_t rec (int64_t n) {
    if (n < MX) {
        return tot[n];
    }
    if (n == 4) {
        return 3;
    }
    if (dp.count(n)) {
        return dp[n];
    }
    if (n % 2 == 0) {
        dp[n] = rec(n/2) * 3 - 1 + rec(n/3);
        for (int64_t a = 1; a * a <= n; a++) {
            if (a % 2 == 0 && a >= 4 && a < n) {
                dp[n] -= rec(n/a);
                dp[n] += rec(n/(a + 1));
            }
            int gamma = n/a;
            if (gamma % 2 == 0 && gamma >= 4 && gamma < n && gamma != a) {
                dp[n] -= rec(n/gamma);
                dp[n] += rec(n/(gamma + 1));
            }
        }
        return dp[n];
    }
    int64_t res = rec(n - 1) + 1;
    for (int64_t j = 1; j * j <= n; j++) {
        if (j == 1 || n % j != 0) {
            continue;
        }
        res -= rec(n/j - 1);
        res += rec(n/j);
        int64_t gamma = n/j;
        if (gamma != j) {
            res -= rec(n/gamma - 1);
            res += rec(n/gamma);
        }
    }
    return (dp[n] = res);
}
int main () {
    int64_t n;
    cin >> n;
    vector<int> fact[MX + 1];
    for (int i = 2; i <= MX; i++) {
        for (int j = i; j <= MX; j += i) {
            fact[j].push_back(i);
        }
    }
    tot[0] = 1;
    tot[1] = 1;
    tot[2] = 1;
    for (int i = 3; i < MX; i++) {
        tot[i] = tot[i - 1] + 1;
        for (int j: fact[i]) {
            tot[i] -= tot[i/j - 1];
            tot[i] += tot[i/j];
        }
    }
    cout << rec(n);
}
