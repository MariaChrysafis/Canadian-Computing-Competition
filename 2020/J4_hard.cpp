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
    int tot = 0;
    for (auto& vec: cnt) {
        for (int i: vec) {
            tot += abs(i);
        }
    }
    if (!tot) {
        cout << "yes";
        exit(0);
    }
    for (int i = 1; i + t.size() - 1 < s.size(); i++) {
        tot -= abs(cnt[s[i + t.size() - 1] - 'A'][s[i] - 'A']);
        cnt[s[i + t.size() - 1] - 'A'][s[i] - 'A']++; //B,F
        tot += abs(cnt[s[i + t.size() - 1] - 'A'][s[i] - 'A']);

        tot -= abs(cnt[s[i + t.size() - 2] - 'A'][s[i - 1] - 'A']);
        cnt[s[i + t.size() - 2] - 'A'][s[i - 1] - 'A']--; //A,E
        tot += abs(cnt[s[i + t.size() - 2] - 'A'][s[i - 1] - 'A']);

        tot -= abs(cnt[s[i - 1] - 'A'][s[i] - 'A']);
        cnt[s[i - 1] - 'A'][s[i] - 'A']--;  //A,B
        tot += abs(cnt[s[i - 1] - 'A'][s[i] - 'A']);

        tot -= abs(cnt[s[i + t.size() - 2] - 'A'][s[i + t.size() - 1] - 'A']);
        cnt[s[i + t.size() - 2] - 'A'][s[i + t.size() - 1] - 'A']++; //D,E
        tot += abs(cnt[s[i + t.size() - 2] - 'A'][s[i + t.size() - 1] - 'A']);

        if (!tot) {
            cout << "yes";
            exit(0);
        }
    }
    cout << "no";
}
