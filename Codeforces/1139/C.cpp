#include<bits/stdc++.h>

using namespace std;

#define ll long long int
#define pb push_back

ll mod = 1E9+7;

ll parti(ll s, vector<pair<ll,ll>> arr[], vector<bool> &visited ){

    ll val =0;
   // if(visited[s] == false){
        visited[s] = true;
        for(auto x: arr[s]){
            if(x.second !=1 && visited[x.first] == false){
                visited[x.first] = true;
                val +=parti(x.first, arr, visited)+1;
            }
        }
   // }
    return val;

}

ll pow(ll a, ll b){
    ll res = 1;
    
    //cout << a << " " << b;
    while(b){
        if(b&1){

            res = (res*a) % mod;
        }
        //cout << b << " : "<< res << "\n";
        a = (a*a) % mod;
        b = b >> 1;
    }
    return res;
}

int main(){
    ll n, k;
    cin >>n >> k;
    vector<pair<ll,ll>> arr[n+1];
    for(ll i=0; i<n; i++){
        ll x,y,z;
        cin >> x >> y >> z;
        arr[x].pb({y,z});
        arr[y].pb({x,z});
    }

    vector<bool> visited(n+1, false);
    ll part = 0;
    for(ll i=1; i<=n; i++){
        if(visited[i] == false){
            ll pp = parti(i, arr, visited)+1;
        //    cout << pp << "\n";
            //pp = (pp == 0) ? 1 : pp;
            pp = pp %mod;
      //      cout << pow(pp, k) << " -- \n";
            part =(part+ pow(pp, k))%mod;
        }
    }
    //cout << pow(n,k) << " " << part << "\n";
    cout << (pow(n,k) - part + mod) % mod << "\n";

    return 0;
}
