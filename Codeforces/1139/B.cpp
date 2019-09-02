#include<bits/stdc++.h>


using namespace std;

#define ll long long int
#define pb push_back
int main(){

    ll n;
    cin >> n;
    vector<ll> arr;
    for(ll i=0; i<n; i++){
        ll val;
        cin >> val;
        arr.pb(val);
    }
    ll ans = arr[n-1];
    ll cut = ans;
    //cerr << ans << "\n";
    for(ll i=n-2; i>=0; i--){
        ll val =min(arr[i], (cut == 0? 0: cut-1));
        ans += val;
        cut = val;
      //  cerr << ans << "\n";
    }

    cout << ans << "\n";
    return 0;
}
