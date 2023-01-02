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
const int MX = 400;
bool can_merge[MX][MX];
bool has_visited[MX][MX];
int pref[MX + 1];
bool rec (int i, int j) {
    if (has_visited[i][j]) {
        return can_merge[i][j];
    }
    has_visited[i][j] = true;
    for (int k = i; k <= j - 1; k++) {
        if (pref[k + 1] - pref[i] == pref[j + 1] - pref[k + 1] && rec(i, k) && rec(k + 1, j)) {
            can_merge[i][j] = true;
        }
    }
    for (int a = i; a < j; a++) {
        for (int b = a + 1; b < j; b++) {
            if (pref[a + 1] - pref[i] == pref[j + 1] - pref[b + 1] && rec(i, a) && rec(a + 1, b) && rec(b + 1, j)) {
                can_merge[i][j] = true;
            }
        }
    }
    return can_merge[i][j];
}
int main () {
    int n;
    cin >> n;
    int arr[n];
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pref[i + 1] = pref[i] + arr[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            can_merge[i][j] = false;
            has_visited[i][j] = false;
        }
        can_merge[i][i] = true;
        has_visited[i][i] = true;
    }
    int myMax = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (rec(i, j)) {
                myMax = max(myMax, pref[j + 1] - pref[i]);
            }
        }
    }
    cout << myMax;
}
