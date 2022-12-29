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
vector<int> prior = {1, 2, 3};

int moves (vector<vector<int> > cnt) {
    for (int i = 0; i < 3; i++) {
        cnt[i][i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < i; j++) {
            int x = min(cnt[i][j], cnt[j][i]);
            ans += x;
            cnt[i][j] -= x, cnt[j][i] -= x;
        }
    }
    int gamma = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            gamma += cnt[i][j];
        }
    }
    return ans + gamma * 2/3;
}

bool comp (char c1, char c2) {
    return (prior[c1 - 'A'] < prior[c2 - 'A']);
}

int solve (string s) {
    int n = s.size();
    string str = s;
    sort(s.begin(), s.end(), comp);
    int oc[3];
    for (int i = 0; i < 3; i++) {
        oc[i] = -1;
    }
    for (int i = 0; i < s.size(); i++) {
        oc[s[i] - 'A'] = max(oc[s[i] - 'A'], i);
    }
    vector<vector<int> >  cnt(3);
    for (int i = 0; i < 3; i++) {
        cnt[i].assign(3, 0);
    }
    for (int i = 0; i < str.size(); i++) {
        cnt[s[i] - 'A'][str[i] - 'A']++;
    }
    int res = INT_MAX;
    for (int _ = 0; _ < s.size(); _++) {
        for (int x = 0; x < 3; x++) {
            if (oc[x] == -1) {
                continue;
            }
            int y = oc[x];
            cnt[s[(y) % n] - 'A'][str[(y - _ + n) % n] - 'A']--;
            cnt[s[(y + 1 + n) % n] - 'A'][str[(y - _ + n) % n] - 'A']++;
        }
        res = min(res, moves(cnt));

    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int a = INT_MAX;
    do {
        a = min(a, solve(s));
    } while (next_permutation(prior.begin(), prior.end()));
    cout << a;
}
