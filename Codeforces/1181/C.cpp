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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n,m;
    cin >> n >> m;

    char ch[n][m];
    ll rt[n][m];
    ll dm[n][m];
    for(ll i=0;i <n; i++){
        for(ll j=0; j<m; j++){
            cin >> ch[i][j];
        }
    }



    for(ll i=0;i <n; i++){
        for(ll j=0; j<m; j++){
            rt[i][j] = 1;
            dm[i][j] = 1;
        }
    }


    for(ll i=0;i <n; i++){
        for(ll j=m-2; j>=0; j--){
            if(ch[i][j] == ch[i][j+1])
                rt[i][j] += rt[i][j+1];
        }
    }

    for(ll j=0;j <m; j++){
        for(ll i=n-2; i>=0; i--){
            if(ch[i][j] == ch[i+1][j])
                dm[i][j] += dm[i+1][j];
        }
    }




    ll fn =0;
    for(ll i=0;i <n; i++){
        for(ll j=0; j<m; j++){

            ll h = dm[i][j];
            ll p = i+h;
            if(p>=n)
                continue;
            if(h != dm[p][j])
                continue;

            h = dm[p][j];
            p +=h;
            if(p>=n)
                continue;
            if(dm[p][j] >= h){
                p += h;

                if(p>n)
                    continue;
                ll ans = INT_MAX;
                for(ll k=i; k<p; k++){
                    ans = min(ans, rt[k][j]);
                }

                fn +=ans;
            }



        }
    }


    cout << fn << "\n";

    return 0;
}
