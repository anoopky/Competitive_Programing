#include <bits/stdc++.h>

using namespace std;

vector<int> get(const string &s) {
    vector<int> res(s.size() + 1);
    for (int i = 0; i < int(s.size()); ++i) {
        res[i + 1] = s[i] - 'a';
    }
    return res;
}

int main() {


#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    int k;
    string s, t;
    cin >> k >> s >> t;
    vector<int> a = get(s), b = get(t);

    for (int i = k; i >= 0; --i) {
        a[i] += b[i];
        if (i) {
            a[i - 1] += a[i] / 26;
            a[i] %= 26;
        }
    }

    for (int i = 0; i <= k; ++i) {
        int rem = a[i] % 2;
        a[i] /= 2;
        if (i + 1 <= k) {
            a[i + 1] += rem * 26;
        } else {
            assert(rem == 0);
        }
    }

    for (int i = 1; i <= k; ++i) {
        cout << char('a' + a[i]);
    }
    cout << endl;

    return 0;
}