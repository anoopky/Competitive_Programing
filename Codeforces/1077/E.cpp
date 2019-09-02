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
    ll arr[n];
     map<ll ,ll> mp;
    for(ll i=0; i<n;i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    ll nn  = (mp.size());

    ll help[nn];
    ll ii =0;
    for(auto x: mp){
        help[ii++] = (x.ss);
    }
    sort(help, help+nn);
    mp.clear();

    ll ans =0;
    for(ll i = help[nn-1]; i>=1; i--){
        ll ind = nn-1;
        ll an = i;
        ll tp = an;
        while(tp%2 == 0 && ind > 0){
            tp/=2;
            ind--;
            if(help[ind] >= tp)
                an += tp;
            else
                break;
        }
        ans = max(ans, an);

    }

    cout <<  ans << "\n";

    return 0;
}
