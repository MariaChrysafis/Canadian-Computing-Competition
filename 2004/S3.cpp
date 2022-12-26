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
const int n = 9;
vector<int> split (string s) {
    vector<int> ans;
    for (int i = 0; i < s.size(); i++) {
        if (i % 3 == 2) {
            continue;
        }
        if (i % 3 == 1) {
            ans.push_back((s[i] - '0' - 1) + n * (s[i - 1] - 'A'));
        }
    }
    return ans;
}
vector<int> vec[90];
string res[90];
string ans[90];
int string_to_int (string x) {
    if (x == "0") {
        return 0;
    }
    return stoi(x);
}
string dfs (int curNode, int t) {
    assert(curNode < 90);
    if (!ans[curNode].empty()) {
        return ans[curNode];
    }
    if (t == 0) {
        return (ans[curNode] = "*");
    }
    if (res[curNode][0] < 'A' || res[curNode][1] > 'Z') {
        return (ans[curNode] = to_string(vec[curNode].back()));
    }
    if (vec[curNode].empty()) {
        return (ans[curNode] = "*");
    }
    int tot = 0;
    for (int x: vec[curNode]) {
        dfs(x, --t);
        if (ans[x] == "*") {
            return (ans[curNode] = "*");
        }
        assert(!ans[x].empty());
        tot += string_to_int(ans[x]);
    }
    return (ans[curNode] = to_string(tot));
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> res[n * i + j];
            if (res[n * i + j][0] >= 'A' && res[n * i + j][0] <= 'Z') {
                vec[i * n + j] = split(res[n * i + j]);
            } else {
                vec[i * n + j].push_back(stoi(res[n * i + j]));
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            cout << dfs(n * i + j, 100) << ' ';
        }
        cout << '\n';
    }
}
