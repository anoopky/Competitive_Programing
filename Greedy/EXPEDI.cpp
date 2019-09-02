#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main(){

    ll t;
    cin >> t;
    while(t--){
        
        ll n;
        cin >> n;
        vector<pair<ll,ll>> arr;
        for(ll i=0; i<n; i++){
            ll x,y;
            cin >> x >> y;
            arr.push_back({x,y});
        }

        ll l,p;
        priority_queue<pair<ll,ll>> pq;
        cin >> l >> p; 
        
        for(ll i=0; i<n; i++){
            arr[i].first = l - arr[i].first;
        
        }
        
        sort(arr.begin(), arr.end()) ;
        
        pair<ll,ll> mx = arr[0];
        //pair<ll,ll> pr = arr[0];
        if(p>=mx.first){
            pq.push({mx.second, mx.first});
        }
        else{
            cout << "-1\n";
            continue;
        }
        ll ans = 0;
        for(ll i=1; i<n; i++){
            //cout << p << "\n";
            if(p >= l)
                break;
            pair<ll,ll> ar = arr[i];
            //cout << p << " " << ar.first << " " << ar.second << "\n";
            while(ar.first > p && !pq.empty()){
                mx = pq.top();
                //cout << mx.first << " " << mx.second << "\n";
                pq.pop();
                ll np = p+mx.first;
                ans++;
                p = np;
            }

            if(ar.first > p)
                break;
            pq.push({ar.second, ar.first});
        }

        if(p>=l){
            cout << ans << "\n";
        }
        else{
             
            while(!pq.empty()){
            
                if(p>=l)
                    break;

                mx = pq.top();
                //cout << p << " " << mx.first << " " << mx.second << "\n";
                pq.pop();
                ll np = p + mx.first;
                ans++;
                p = np;
            }

            if(p>=l)
                cout << ans << "\n";
            else
                cout << "-1\n";
        }
    }
    return 0;
}
