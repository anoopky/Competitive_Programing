#include <bits/stdc++.h>
#define ll long long int
#define vll vector<ll>
#define ff first
#define ss second
#define pb push_back

using namespace std;

ll minp(pair<ll,ll> pp){

    return min(pp.ff, pp.ss);
}

pair<ll, ll> addp(pair<ll,ll> pp, pair<ll,ll> pp1){

    return {pp.ff+pp1.ff, pp.ss+pp1.ss};
}


pair<ll, ll> minpp(pair<ll,ll> pp, pair<ll,ll> pp1){

    return minp(pp) < minp(pp1) ? pp1 : pp ;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n,k;
    cin >> n >> k;
    vll arr(n);
    for (ll i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<pair<ll, ll>> tmp(n);
    for(ll i=0; i<n; i++){
        ll tp2 = arr[i];
        ll tp5 = arr[i];
        ll count2 = 0;
        ll count5 = 0;
        while(tp2%2 == 0){
            count2++;
            tp2/=2;
        }
        while(tp5%5 == 0){
            count5++;
            tp5/=5;
        }

        tmp[i] = {count2, count5};


    }



    return 0;
}
