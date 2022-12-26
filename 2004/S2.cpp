#include <bits/stdc++.h>

using namespace std;

bool comp (pair<int,int> p1, pair<int,int> p2) {
    return (p1.second < p2.second);
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int> > tot(n);
    vector<int> worst_rank;
    worst_rank.assign(n, 0);
    for (int i = 0; i < tot.size(); i++) {
        tot[i].first = 0, tot[i].second = i;
    }
    int arr[k][n];
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            tot[j].first += arr[i][j];
        }
        sort(tot.begin(), tot.end());
        reverse(tot.begin(), tot.end());
        map<int,int> myMap;
        for (int j = 0; j < tot.size(); j++) {
            if (!myMap.count(tot[j].first)) myMap[tot[j].first] = j;
        }
        for (int j = 0; j < tot.size(); j++) {
            worst_rank[tot[j].second] = max(myMap[tot[j].first], worst_rank[tot[j].second]);
        }
        sort(tot.begin(), tot.end(), comp);
    }
    sort(tot.begin(), tot.end());
    int mx = tot.back().first;
    for (auto& p: tot) {
        if (p.first == mx) {
            cout << "Yodeller " << p.second + 1 << " is the TopYodeller: score " << p.first << ", worst rank " << worst_rank[p.second] + 1 << '\n';
        }
    }
}
