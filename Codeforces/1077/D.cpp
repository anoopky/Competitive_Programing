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

vector<ll> mp(2*100000+7,0);


bool check(ll md, vector<ll> &ans, ll k){
    ans.clear();

    for(ll i=0; i< (2*100000+7); i++){

        ll need = min((mp[i] / md), (k - int(ans.size())));
        for(ll j=0; j<need; j++){
            ans.pb(i);
        }

    }

    return k == int(ans.size());

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif


    ll n,k;
    cin >> n >> k;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    vector<ll> ans;
    ll s =0, e = n;
    while( e-s > 1){
        ll md = (s+e)/2;

        if(check(md, ans, k ))
            s = md;
        else
            e = md;
    }
    if(!check(e, ans, k)) check(s, ans, k);

    for(auto x: ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
