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
const int dx[4][2] = {{0,  1},
                      {0,  -1},
                      {1,  0},
                      {-1, 0}};
const int dxx[8][2] = {{0,  1},
                       {0,  -1},
                       {1,  0},
                       {-1, 0},
                       {1,  1},
                       {1,  -1},
                       {-1, 1},
                       {-1, -1}};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n;
    cin >> n;
    string str, str1;
    cin >> str;
    cin >> str1;
    ll n1, n2;
    n1 = str.length();
    n2 = str1.length();

    vector<pair<ll, ll>> arr[27];
    vector<pair<ll, ll>> arr1[27];
    ll p1, q1;
    ll p2, q2;
    p1 = q1 = p2 = q2 = 0;
    ll ans = 0;
    F0(n1) {
        if (str[i] != '?') {
            p1++;
            arr[str[i] - 'a'].pb({str[i], i});
        } else {
            arr[26].pb({'?', i});
            q1++;
        }
    }

    F0(n2) {
        if (str1[i] != '?') {
            p2++;
            arr1[str1[i] - 'a'].pb({str1[i], i});
        } else {
            arr1[26].pb({'?', i});
            q2++;
        }
    }

    vector<pair<ll, ll>> vans;
    F0(26) {
        ll mn = min(arr[i].size(), arr1[i].size());
        for (ll i1 = 1; i1 <= mn; i1++) {
            vans.pb({arr[i][arr[i].size() - 1].ss, arr1[i][arr1[i].size() - 1].ss});
            ans++;
            arr[i].pop_back();
            arr1[i].pop_back();

        }

    }


    ll fg = 0;
    for (ll k = 1; k <= arr[26].size(); k++) {

        F0(26) {
            if (fg) {
                fg = 0;
                break;
            }
            for (ll i1 = 1; i1 <= arr1[i].size(); i1++) {
//                if(arr1[i][i1].ff != '-'){
                ans++;
                vans.pb({arr[26][arr[26].size() - 1].ss, arr1[i][arr1[i].size() - 1].ss});
                arr[26].pop_back();
                arr1[i].pop_back();
                fg = 1;
                break;


//                }
            }
        }
    }

    fg = 0;
    for (ll k = 1; k <= arr1[26].size(); k++) {

        F0(26) {
            if (fg) {
                fg = 0;
                break;
            }
            for (ll i1 = 1; i1 <= arr[i].size(); i1++) {
//                if(arr1[i][i1].ff != '-'){
                ans++;
                vans.pb({arr[i][arr[i].size() - 1].ss, arr1[26][arr1[26].size() - 1].ss});
                arr1[26].pop_back();
                arr[i].pop_back();
                fg = 1;
                break;


//                }
            }
        }
    }

    for (ll k = 0; k < arr1[26].size(); k++) {
//        if(arr1[26][k].ff != '-'){
        for (ll i1 = 0; i1 < arr[26].size(); i1++) {
//                if(arr[26][i1].ff != '-'){
            ans++;
//                    arr1[26][k].ff = '-';
//                    arr[26][i1].ff = '-';
            vans.pb({arr[26][arr[26].size() - 1].ss, arr1[26][arr1[26].size() - 1].ss});
            arr1[26].pop_back();
            arr[26].pop_back();
            break;


        }
    }
//}
//}

    for (ll k = 0; k < arr[26].size(); k++) {
//        if(arr1[26][k].ff != '-'){
        for (ll i1 = 0; i1 < arr1[26].size(); i1++) {
//                if(arr[26][i1].ff != '-'){
            ans++;
//                    arr1[26][k].ff = '-';
//                    arr[26][i1].ff = '-';
            vans.pb({arr[26][arr[26].size() - 1].ss, arr1[26][arr1[26].size() - 1].ss});
            arr1[26].pop_back();
            arr[26].pop_back();
            break;


        }
    }


    cout << ans << "\n";
    for (
        auto x
            : vans) {
        cout << x.ff + 1 << " " << x.ss + 1 << "\n";
    }

    return 0;
}
