#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define ff first
#define ss second
#define pb push_back
#define all(arr) arr.begin(), arr.end()
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
#define Darr(arr,n) for(ll i=0; i<n; i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define Dvarr(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define Dauto(arr) for(auto x: arr) cerr << x << " " ; cerr<< endl;

#define Fi(i,L,R) for (ll i = (L); i < (R); i++)
#define F(L,R) for (ll i = (L); i < (R); i++)
#define F0(R) F(0,R)
#define F1(R) F(1,R)
#define FE(L,R) for (ll i = (L); i <=(R); i++)
#define FE0(R) F(0,R)
#define FE1(R) F(1,R)
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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n;
    cin >> n;
    ll a,b,c;
    cin >> a >> b >> c;

    ll arr[n];
    F0(n){
        cin >> arr[i];
    }

    vll dp(n,INT_MIN),dp1(n,INT_MIN),dp2(n,INT_MIN);
    dp[0] =  arr[0]*a;
    dp1[0] =  dp[0]+arr[0]*b;
    dp2[0] =  dp1[0]+arr[0]*c;
    F1(n){
        dp[i] = max(dp[i-1], arr[i]*a);
        dp1[i] = max(dp1[i-1], max(dp[i-1]+arr[i]*b, dp[i]+arr[i]*b));
        dp2[i] = max(dp2[i-1], max(dp1[i-1]+arr[i]*c, dp1[i]+arr[i]*c));
    }

    cout << dp2[n-1] << "\n";
    return 0;
}
