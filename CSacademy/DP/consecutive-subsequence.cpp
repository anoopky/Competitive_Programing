#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define ff first
#define ss second
#define pb emplace_back
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
#define Dvarr(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define Darr(arr,n) for(ll i=0; i<n; i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;

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
const int INF = 1000000005;
const ll INFF = 1000000000000000005LL;
const double PI = acos(-1);
const int IMAX = 1e8; // int
const int LMAX = 1e7; // ll
const int MAX = 1e6;
const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

ll arr[MAX];
ll n;
map<pair<int,bool>, ll> mp;

ll solve(int ind, bool used){

    if((ind+1)>=n)
        return used == 1 ? 1 : 2;

    ll ans = 1;
    ll ck = arr[ind];
    if(mp.find({ind, used}) != mp.end()){
        return mp[{ind, used}];
    }
    F(ind+1, n){
        if((ck+1) == arr[i]){
            ans = max(ans, 1+solve(i, used));
        }
        else if((ck+2) == arr[i] && !used){
            ans = max(ans, 2+solve(i, 1));
        }
    }
    mp[{ind, used}] = ans;
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    cin >> n;
    F0(n){
        cin >> arr[i];
    }
    ll ans = 0;
//    F0(n){
//        ans = max(ans, solve(i, 0));
//    }
    vector<pair<ll,ll>> dp(n,{1,1});
    F0(n){
        ll j;
        Fi(j, i+1, n){
            if((arr[i]+1) ==  arr[j]){

            }
            else if((arr[i]+2) ==  arr[j]){

            }

        }
    }
    bool fg=0;
    ll mx=0, mxi=0;
    F0(n){
        if(max(dp[i].ff, dp[i].ss) >  mx){
            mx = max(dp[i].ff, dp[i].ss);
            mxi = i;
        }
        if(max(dp[i].ff, dp[i].ss) == mx && dp[i].ss == 1){
            mx = max(dp[i].ff, dp[i].ss);
            mxi = i;
        }
    }
    ans = max(dp[mxi].ff, dp[mxi].ss);
    if(dp[mxi].ss == 1)
        ans+=1;
    cout << ans << "\n";


    return 0;
}
