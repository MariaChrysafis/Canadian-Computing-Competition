#include <bits/stdc++.h>
using namespace std;
void okay (vector<vector<int> > cnt) {
    for (int i = 0; i < cnt.size(); i++) {
        for (int j: cnt[i]) {
            if (j != 0) {
                return;
            }
        }
    }
    cout << "yes\n";
    exit(0);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s, t;
    cin >> s >> t;
    vector<vector<int> > cnt(26);
    for (int i = 0; i < 26; i++) {
        cnt[i].assign(26, 0);
    }
    for (int i = 0; i < t.size(); i++) {
        cnt[t[i] - 'A'][t[(i + 1) % t.size()] - 'A']--;
    }
    for (int i = 0; i < t.size(); i++) {
        cnt[s[i] - 'A'][(s[(i + 1) % t.size()]) - 'A']++;
    }
    okay(cnt);
    for (int i = 1; i + t.size() - 1 < s.size(); i++) {
        cnt[s[i + t.size() - 1] - 'A'][s[i] - 'A']++; //B,F
        cnt[s[i + t.size() - 2] - 'A'][s[i - 1] - 'A']--; //A,E
        cnt[s[i - 1] - 'A'][s[i] - 'A']--;  //A,B
        cnt[s[i + t.size() - 2] - 'A'][s[i + t.size() - 1] - 'A']++; //D,E
        okay(cnt);
    }
    cout << "no";
}
