#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define vll vector<ll>
#define vll2(arr,n,m) vector<vll> arr(n, vll(m))
#define vll2v(arr,n,m,v) vector<vll> arr(n, vll(m, v))
#define ff first
#define ss second
#define pb push_back
#define all(arr) arr.begin(), arr.end()
#define ED cout<<endl;
#define D1(x) (cerr << #x << ": " << x << " ")
#define D2(x,y) (cerr << #x << ": " << x << ", " << #y << ": " << y << " ")
#define D3(x,y,z) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << " " )
#define D4(x,y,z,a) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << ", " << #a << ": " << a << " " )
#define D1e(x) (D1(x) << endl)
#define D2e(x,y) (D2(x,y) << endl)
#define D3e(x,y,z) (D3(x,y,z) << endl)
#define D4e(x,y,z,a) (D4(x,y,z,a) << endl)
#define Dsp cerr << " ||  ";
#define Dspe cerr << " || "<< endl;
#define DA(arr,n) for(ll i=0; i<n; i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DvA(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DAu(arr) for(auto x: arr) cerr << x << " " ; cerr<< endl;
#define maxvA(arr) arr[max_element(all(arr)) - arr.begin()]
#define minvA(arr) arr[min_element(all(arr)) - arr.begin()]
#define maxA(arr,n) arr[max_element(arr, arr+n) - arr]
#define minA(arr,n) arr[min_element(arr, arr+n) - arr]

#define Fi(i,L,R) for (ll i = (L); i < (R); i++)
#define F(L,R) for (ll i = (L); i < (R); i++)
#define F0(R) F(0,R)
#define F1(R) F(1,R)
#define FEi(i,L,R) for (ll i = (L); i <=(R); i++)
#define FE(L,R) for (ll i = (L); i <=(R); i++)
#define FE0(R) FE(0,R)
#define FE1(R) FE(1,R)
#define FR(L,R) for (ll i = L; i > R; i--)
#define FRE(L,R) for (ll i = L; i >= R; i--)

using namespace std;

const double EPS = 1e-9;
const ll MOD = (1e9)+7;
const int INF = 1000000005;
const ll INFF = 1000000000000000005LL;
const double PI = acos(-1);
const int MAX8 = 1e8; // int
const int MAX7 = 1e7; // ll
const int MAX6 = 1e6;
const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};


bool isin(pair<pair<ll,ll>,ll> s, ll x1,ll y1,ll x2,ll y2){
    ll tx, ty;
    tx = s.ff.ff;
    ty = s.ff.ss;
    if(tx >= x1 && tx <= x2 && ty >=y1 && ty <= y2)
        return true;
    else
        return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n,q,c;
    cin >> n >> q >> c;

    vector<pair<pair<ll,ll>,ll>>  star(n);
    F0(n){
        ll x,y,ci;
        cin >> x >> y >> ci;
        star[i] = {{x,y}, ci};
    }

    vector<vector<pair<ll,ll>>> dp(101, vector<pair<ll,ll>>(101));
    F1(101){
        Fi(k,1,101){
            ll cc =0;
            ll pp = 0;
            Fi(j,0,n){
                if(isin(star[j], 1,1,i,k)){
                    cc++;
                    pp += (star[j].ss);
                }
            }

            dp[i][k] = {pp, cc};
        }
    }
    F0(q){
        ll t, x1,y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;

        pair<ll,ll> v1 = dp[x1-1][y1-1];
        pair<ll,ll> v2 = dp[x2][y2];
        pair<ll,ll> v3 = dp[x2][y1-1];
            pair<ll,ll> v4 = dp[x1-1][y2];

        ll ans = v2.ff + v1.ff - v3.ff - v4.ff;
        ll ans1 = v2.ss + v1.ss - v3.ss - v4.ss;

//        D2e(ans, ans1);
        ll mx = (ans + (ans1*t)) %(c+1);

        cout << mx; ED;
    }


    return 0;
}