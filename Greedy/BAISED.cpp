#include<bits/stdc++.h>

using namespace std;

#define ll long long int
int main(){

    ll t;
    cin >> t;
    while(t--){
        
        ll n;
        cin >> n;
        vector<ll> arr;
        while(n--){
            string s;
            ll x;
            cin >> s >> x;

            arr.push_back(x);
        
        }

        sort(arr.begin(), arr.end());
        ll ans =0;
        for(ll i=0; i<arr.size(); i++){
        
            ans += abs(arr[i] - i - 1);
        }
    
        cout << ans <<"\n";
    }

    return 0;

}
