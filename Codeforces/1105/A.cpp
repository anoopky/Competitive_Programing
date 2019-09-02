#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
    ll n;
#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif
    cin >> n;
    ll arr[n];

    for(ll i=0; i<n; i++){
        cin >> arr[i];
    }

    pair<ll,ll> ans = {1,INT_MAX};
    for(ll val =1; val<=100; val++){
        ll cost = 0;
        for(ll i=0; i<n; i++){

            ll v1 = val;
            ll v2 = val+1;
            ll v3 = val-1;

            cost += min(abs(arr[i] - v1), min(abs(arr[i]-v2) , abs(arr[i]-v3)));

        }

        if(ans.second > cost){
            ans = {val, cost};
        }


    }



        cout << ans.first << " " << ans.second << "\n";



}