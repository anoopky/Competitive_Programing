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

vector<ll> p(200007);
ll arr[200007];


ll leader(ll x){

    return (p[x] == x ? x : (p[x] = leader(p[x])));

}

bool merge(ll x, ll y){

    ll p1 = leader(x);
    ll p2 = leader(y);
    if(p1 == p2)
        return false;
    else{
        p[p1] = p2;
        return true;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("./input", "r", stdin);
    ll n,m;
    cin >> n >> m;
    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<tuple<ll,ll,ll>> ed;
    for(ll i=0;i<m; i++){
        ll x,y,w;
        cin >> x >>y >> w;
        x-=1;
        y-=1;
        ed.pb({w,x,y});
    }

    ll mn = min_element(arr, arr+n) - arr;
//    cout << mn << "\n";

    for(ll i=0; i<n; i++){
        if(i!=mn){
            ed.push_back({arr[i]+arr[mn], i, mn});
        }
    }

    sort(ed.begin(), ed.end());

    for(ll i=0; i<n; i++)
        p[i] = i;
    ll ans =0;
//    Darr(p);
    for(auto x1: ed){
        ll x,y,z;
        tie(x,y,z) = x1;
        if(merge(y,z)){
            ans += x;
//            D3e(y,z,x);
        }
//        Darr(p);

    }

    cout << ans << "\n";

    return 0;

}
