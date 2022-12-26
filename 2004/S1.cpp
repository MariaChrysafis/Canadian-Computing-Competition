#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cassert>
#include <bitset>
#include <queue>
#include <cmath>
#include <map>
#include <unordered_map>
#include <stack>
#include <ctime>

using namespace std;
bool is_okay (string a, string b) {
    bool fine = true;
    for (int i = 0; i < min(a.size(), b.size()); i++) {
        fine &= (a[i] == b[i]);
    }
    if (fine) {
        return true;
    }
    int x1 = a.size(), x2 = b.size();
    while (x1 && x2) {
        x1--, x2--;
        if (a[x1] != b[x2]) {
            return false;
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a >> b >> c;
        cout << ((!is_okay(a, b) && !is_okay(b, c) && !is_okay(a, c)) ? "Yes" : "No") << '\n';
    }
}
