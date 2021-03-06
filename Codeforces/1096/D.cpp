#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

const int N = 100 * 1000 + 13;
const long long INF64 = 1e18;

int n;
string s;
int a[N];
long long dp[N][5];

const string h = "hard";

void dis(int n){
    for(int i=0; i<=n; i++){
        for(int j=0; j<5; j++){
            cout << (dp[i][j] == 1000000000000000000 ? -1 : dp[i][j]) << " ";
        }

        cout << "\n";
    }

    cout << "\n";

}

int main() {

    freopen("./input", "r", stdin);

    scanf("%d", &n);
    static char buf[N];
    scanf("%s", buf);
    s = buf;
    forn(i, n)
        scanf("%d", &a[i]);

    forn(i, N) forn(j, 5) dp[i][j] = INF64;
    dp[0][0] = 0;
    forn(i, n) forn(j, 4){
            dp[i + 1][j + (s[i] == h[j])] = min(dp[i + 1][j + (s[i] == h[j])], dp[i][j]);
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + a[i]);
            dis(n);

        }

    printf("%lld\n", *min_element(dp[n], dp[n] + 4));
    return 0;
}