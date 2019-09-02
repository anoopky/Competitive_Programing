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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n;
    cin >> n;
    vector<ll> val;
    ll ans =0;
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        if(x >= 0)
            ans+=x;
        else
            val.pb(x);

    }

    sort(val.begin(), val.end(), greater<>());
    ll i = 0;
    if(val.size() == n){
        ans +=val[0];

    }

    if(val.size() %2 == 0 ){
            ans +=val[0];
            i = 2;

    }
    else
    i = 1;

    for(; i<val.size(); i+=2){
        ans+=val[i];
    }

    cout << ans << "\n";
    return 0;
}
