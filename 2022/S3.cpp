#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MOD1 = 1e9 + 9;
int64_t binPow (int64_t x, int64_t y, int mod) {
    int64_t ans = 1;
    int64_t res = x;
    while (y > 0) {
        if (y & 1) {
            ans *= res;
            ans %= mod;
        }
        res *= res;
        res %= mod;
        y >>= 1;
    }
    return ans;
}
const int THING = 10009;
int main() {
    string s, t;
    cin >> s >> t;
    if (s.length() > t.length()) {
        cout << 0;
        return 0;
    }
    vector<int> oc(26);
    vector<int> oc_des(26);
    int arr[26];
    for (int i = 0; i < 26; i++) {
        arr[i] = i + 3;
    }
    int64_t soFar = 0;
    int64_t soFar1 = 0;
    for (int i = 0; i < s.length(); i++) {
        oc[t[i] - 'a']++;
        oc_des[s[i] - 'a']++;
        soFar = THING * soFar + arr[t[i] - 'a'];
        soFar1 = THING * soFar1 + arr[t[i] - 'a'];
        soFar %= MOD;
        soFar1 %= MOD1;
    }
    set<int64_t> mySet;
    for (int i = 0; i <= t.length() - s.length(); i++) {
        if (oc == oc_des) {
            mySet.insert(soFar1 * soFar);
        }
        if (i == t.length() - s.length()) {
            break;
        }
        oc[t[i] - 'a']--;
        oc[t[i + s.length()] - 'a']++;
        soFar -= (binPow(THING, (int)s.length() - 1, MOD) * arr[t[i] - 'a']) % MOD - MOD, soFar %= MOD, soFar *= THING, soFar %= MOD, soFar += arr[t[i + s.length()] - 'a'], soFar %= MOD;
        soFar1 -= (binPow(THING, (int)s.length() - 1, MOD1) * arr[t[i] - 'a']) % MOD1 - MOD1, soFar1 %= MOD1, soFar1 *= THING, soFar1 %= MOD1, soFar1 += arr[t[i + s.length()] - 'a'], soFar1 %= MOD1;

    }
    cout << mySet.size() << endl;
}
