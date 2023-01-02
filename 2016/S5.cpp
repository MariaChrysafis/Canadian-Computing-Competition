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
string rotate (int64_t n, string s) {
    n %= s.size();
    string str = "";
    for (int i = 0; i < s.size(); i++) {
        str += ((((s[(i - n + s.size()) % s.size()] == '1') ^ (s[(i + n) % s.size()] == '1')) == 1) ? '1' : '0');
    }
    return str;
}
int main () {
    int64_t n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for (int64_t i = 60; i >= 0; i--) {
        if ((1ll << i) & k) {
            s = rotate((1ll << i), s);
        }
    }
    cout << s;
}
