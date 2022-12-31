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
    int n;
    cin >> n;
    vector<int64_t> v(n);
    const int MAX = 500001;
    int myMap[MAX], cnt[MAX];
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        myMap[v[i]] = i;
    }
    for (int i = 0; i < MAX; i++) {
        cnt[i] = 0;
    }
    double suf[n];
    double tot = 0;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = 0;
        cnt[v[i]]++;
        if (myMap[v[i]] != i) {
            tot += suf[myMap[v[i]]];
        }
        if (v[n - 1] == v[i]) {
            suf[i] = 1;
        } else {
            if (v[0] == v[i]) {
                suf[i] -= cnt[v[i]];
            } else if (v[i] != v[n - 1]) {
                suf[i] -= cnt[v[0]] * suf[myMap[v[0]]];
            }
            suf[i] += cnt[v[i]] + tot - cnt[v[n - 1]] * suf[myMap[v[n - 1]]] + cnt[v[0]];
            if (myMap[v[i]] != i && v[n - 1] != v[i]) {
                suf[i] -= cnt[v[i]] * suf[myMap[v[i]]];
            }
            suf[i] /= double(n - 1 - i + 1);
        }
        if (myMap[v[i]] == i) {
            tot += suf[myMap[v[i]]];
        }
    }
    cout << setprecision(30) << suf[0] << '\n';
}
