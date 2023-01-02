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
int main () {
    string a, b;
    cin >> a >> b;
    map<char,int> m;
    for (int i = 0; i < a.size(); i++) {
        m[a[i]]++, m[b[i]]--;
    }
    for (auto& p: m) {
        if (p.second < 0 && p.first != '*') {
            cout << "N";
            exit(0);
        }
    }
    cout << "A";
}
