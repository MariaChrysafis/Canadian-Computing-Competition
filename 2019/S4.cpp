#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <iomanip>
#include <bitset>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#include <stack>
#include <ctime>

using namespace std;

struct SparseTable {
    vector<vector<int64_t> > dp;

    int64_t query(int l, int r) {
        if (l > r) return 0;
        int sz = log2(r - l + 1);
        return max(dp[l][sz], dp[r - (1 << sz) + 1][sz]);
    }

    SparseTable(int n) {
        dp.resize(n);
        for (int i = 0; i < n; i++) {
            dp[i].resize(log2(n) + 1);
        }
    }

    void resz (vector<int64_t> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            dp[i][0] = arr[i];
        }
        for (int j = 1; j < dp[0].size(); j++) {
            for (int i = 0; i < n; i++) {
                dp[i][j] = max(dp[i][j - 1], dp[min(i + (1 << (j - 1)), n - 1)][j - 1]);
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int64_t> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int64_t dp[n + 1];
    for (int i = 0; i <= n; i++) {
        dp[i] = 0;
    }
    for (int i = 1; i <= k; i++) {
        dp[i] = max(dp[i - 1], arr[i]);
    }
    SparseTable st_prev_dp(k);
    SparseTable st_tot(k);
    for (int i = 1; i < (n + k - 1)/k; i++) {
        vector<int64_t> prev_dp(k);
        int c = 0;
        for (int prev = k * i + 1 - k; prev <= k * i; prev++) {
            prev_dp[c++] = dp[prev];
        }
        int64_t pref[k];
        pref[k - 1] = 0;
        for (int ind = k - 2; ind >= 0; ind--) {
            pref[ind] = max(pref[ind + 1], arr[ind + k * (i - 1) + 2]);
        }
        st_prev_dp.resz(prev_dp);
        vector<int64_t> tot(k);
        for (int ind = 0; ind < k; ind++) {
            tot[ind] = dp[k * i + 1 - k + ind] + pref[ind];
        }
        st_tot.resz(tot);
        int new_bounds = k - 1;
        for (int cur = 0; cur < k && cur + k * i + 1 <= n; cur++) {
            if (arr[cur + k * i + 1] > pref[k - 1]) {
                while (new_bounds >= 1 && pref[new_bounds - 1] < arr[cur + k * i + 1]) {
                    new_bounds--;
                }
            }
            pref[k - 1] = max(arr[cur + k * i + 1], pref[k - 1]);
            dp[cur + k * i + 1] =  st_tot.query(cur, new_bounds - 1);
            dp[cur + k * i + 1] = max(dp[cur + k * i + 1], pref[k - 1] + st_prev_dp.query(max(cur, new_bounds), k - 1));
        }
    }
    cout << dp[n];
}
