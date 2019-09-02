#include <bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define pb push_back
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
#define Darr(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;

using namespace std;

ll mxe(vector<ll> arr, ll s, ll e){

    ll mx =0;
    for(ll i=s; i<e; i++){
        if(mx<=arr[i])
            mx = arr[i];
    }

    return mx;
}

ll solve(ll cost, ll arr[], ll i, ll rest, ll used, ll k, ll x, ll n){


    if(i >= n   || used >= x ){
        if((n-i) >= k)
            return -1;
        else
            return cost;

    }

    if(rest == k)
        return arr[i];

//    D4(cost, i, rest, used); D3e(k, x, n);


    ll ans = -1;
    for(ll ii = i; ii<n; ii++){
        ll vv = arr[ii];
        ll val = max(solve(cost, arr, ii+1, rest+1, used, k, x, n), solve(cost+vv, arr, ii+1, 0, used+1, k, x, n));
        ans = max(ans, val);
    }

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n, k, x;
    cin >> n >> k >> x;
    ll arr[n];
    for(ll i=0; i<n; i++)
        cin >> arr[i];

    if((n/k) > x){
        cout << "-1\n";
        return 0;
    }


    cout << solve(0, arr, 0, 0, 0, k, x, n) << "\n";
    return 0;
}
