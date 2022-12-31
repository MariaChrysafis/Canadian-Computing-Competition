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
    int t;
    cin >> t;
    vector<pair<int64_t,int64_t> > vec;
    while (t--) {
        int x, y;
        cin >> x >> y;
        vec.emplace_back(x, y);
    }
    sort(vec.begin(), vec.end());
    double myMax = 0;
    for (int i = 1; i < vec.size(); i++) {
        int64_t d1 = abs(vec[i].first - vec[i - 1].first);
        int64_t d2 = abs(vec[i].second - vec[i - 1].second);
        myMax = max(myMax, double(d2)/double(d1));
    }
    cout << myMax;
}
