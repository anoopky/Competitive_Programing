#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define vll vector<ll>
#define vll2(arr, n, m) vector<vll> arr(n, vll(m))
#define vll2v(arr, n, m, v) vector<vll> arr(n, vll(m, v))
#define ff first
#define ss second
#define pb push_back
#define all(arr) arr.begin(), arr.end()
#define ED cout<<endl;
#define D1(x) (cerr << #x << ": " << x << " ")
#define D2(x, y) (cerr << #x << ": " << x << ", " << #y << ": " << y << " ")
#define D3(x, y, z) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << " " )
#define D4(x, y, z, a) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << ", " << #a << ": " << a << " " )
#define D1e(x) (D1(x) << endl)
#define D2e(x, y) (D2(x,y) << endl)
#define D3e(x, y, z) (D3(x,y,z) << endl)
#define D4e(x, y, z, a) (D4(x,y,z,a) << endl)
#define Dsp cerr << " ||  ";
#define Dspe cerr << " || "<< endl;
#define DA(arr, n) for(ll i=0; i<n; i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DvA(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DAu(arr) for(auto x: arr) cerr << x << " " ; cerr<< endl;
#define maxvA(arr) arr[max_element(all(arr)) - arr.begin()]
#define minvA(arr) arr[min_element(all(arr)) - arr.begin()]
#define maxA(arr, n) arr[max_element(arr, arr+n) - arr]
#define minA(arr, n) arr[min_element(arr, arr+n) - arr]

#define Fi(i, L, R) for (ll i = (L); i < (R); i++)
#define F(L, R) for (ll i = (L); i < (R); i++)
#define F0(R) F(0,R)
#define F1(R) F(1,R)
#define FEi(i, L, R) for (ll i = (L); i <=(R); i++)
#define FE(L, R) for (ll i = (L); i <=(R); i++)
#define FE0(R) FE(0,R)
#define FE1(R) FE(1,R)
#define FR(L, R) for (ll i = L; i > R; i--)
#define FRE(L, R) for (ll i = L; i >= R; i--)

using namespace std;

const double EPS = 1e-9;
const ll MOD = (1e9) + 7;
const int INF = 1000000005;
const ll INFF = 1000000000000000005LL;
const double PI = acos(-1);
const int M8 = 1e8; // int
const int M7 = 1e7; // ll
const int M6 = 1e6;
const int M5 = 1e5;
const int dx[4][2] = {{0,  1},{0,  -1},{1,  0},{-1, 0}};
const int dxx[8][2] = {{0,  1},{0,  -1},{1,  0},{-1, 0},{1,  1},{1,  -1},{-1, 1},{-1, -1}};

const int N = 200050;
long long ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    int n, W = 0;

    scanf("%d", &n);
    vector<int> one, two;
    for (int i = 0; i < n; i++) {
        int w, c;
        scanf("%d %d", &w, &c);
        if (w == 1) one.push_back(c);
        else two.push_back(c);
        W += w;
    }

    sort(one.begin(), one.end());
    sort(two.begin(), two.end());

    vector<int> ONE = one, TWO = two;

    // construct even
    long long cur = 0;
    for (int w = 2; w <= W; w += 2) {
        int cost1 = 0, cost2 = 0;
        if (two.size() >= 1) {
            cost1 = two.back();
        }
        int flag = 1;
        if (one.size() >= 2) {
            cost2 = one.back();
            cost2 += one[one.size() - 2];
        } else if (one.size() >= 1) {
            flag = 2;
            cost2 = one.back();
        }
        if (cost1 > cost2) {
            cur += cost1;
            two.pop_back();
        } else {
            cur += cost2;
            if (flag == 1) {
                one.pop_back();
                one.pop_back();
            } else {
                one.pop_back();
            }
        }
        ans[w] = cur;
    }

    // construct odd
    one = ONE, two = TWO;
    cur = 0;
    if (one.size() >= 1) {
        cur = one.back();
        one.pop_back();
    }
    ans[1] = cur;
    for (int w = 3; w <= W; w += 2) {
        int cost1 = 0, cost2 = 0;
        if (two.size() >= 1) {
            cost1 = two.back();
        }
        int flag = 1;
        if (one.size() >= 2) {
            cost2 = one.back();
            cost2 += one[one.size() - 2];
        } else if (one.size() >= 1) {
            flag = 2;
            cost2 = one.back();
        }
        if (cost1 > cost2) {
            cur += cost1;
            two.pop_back();
        } else {
            cur += cost2;
            if (flag == 1) {
                one.pop_back();
                one.pop_back();
            } else {
                one.pop_back();
            }
        }
        ans[w] = cur;
    }
    for (int w = 1; w <= W; w++) {
        if (w > 1) printf(" ");
        printf("%lld", ans[w]);
    }
    printf("\n");
    return 0;

//    return 0;
}
