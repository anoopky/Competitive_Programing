#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int kMaxN = 1e5;


int main() {
#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif
    int where[kMaxN];

    int n;
    cin >> n;

    for (int i = 0; i < n; i += 1) {
        int x;
        cin >> x;
//        x -= 1;
        where[x] = i;
    }

    int left = n, right = 0;
    int mx = 0;

    for (int i = n - 1, num = 1; i >= 0; i -= 1, num += 1) {
        left = min(left, where[i]);
        right = max(right, where[i]);
        mx = max(mx, (right - left) - num + 3);
    }

    if (n == 1) {
        mx = 1;
    }

    cout << mx << '\n';
    return 0;
}
