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
bool isPrime (int n) {
    if (n == 1) {
        return false;
    }
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        int64_t n;
        cin >> n;
        n *= 2;
        for (int i = 1; i <= n; i += 2) {
            if (isPrime(n - i) && isPrime(i)) {
                cout << i << " " << n - i << '\n';
                break;
            }
        }
    }
}
