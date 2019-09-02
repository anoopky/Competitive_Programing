#include<bits/stdc++.h>

#define ll long long int

using namespace std;

int main(){

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<pair<ll,ll>> arr;
        while(n--){
            ll x,y;
            cin >> x >> y;
            arr.push_back({y,x});
        }

        sort(arr.begin(), arr.end());

        ll ft = arr[0].first;
        ll st = arr[0].second;
        ll ans = 1;
        for(ll i=1; i<arr.size(); i++){
            
            ll st1 = arr[i].second;
            if(st1 >= ft){
                ft = arr[i].first;
                ans++;
            }
        }


        cout << ans << "\n";
    }
   
    return 0;

}
