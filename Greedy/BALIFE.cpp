#include<bits/stdc++.h>

using namespace std;

#define ll long long int
int main(){
    
    while(1){
        ll x;
        cin >> x;
        if(x == -1)
            break;

        ll sm =0;
        vector<ll> arr;
        for(ll i=0; i<x; i++){
        
            ll n;
            cin >> n;
            sm +=n;
            arr.push_back(sm);
        }
    
        if(sm % x == 0){
            ll n = arr.size();
            ll ans = 0;
            for(ll i=0; i<arr.size()-1; i++){
                
                ll p1 = arr[i];
                ll p2 = arr[n-1] - arr[i];
                ll mst = sm / x;
                //cout << p1 << " " << p2 << " " << mst << " " << ans << "\n";
                if(p1 < mst*(i+1)){
                    ans = max(ans, mst*(i+1) - p1);
                }
                else{
                    ans = max(ans, mst*(n-i-1) - p2);
                }
                //ans = max(ans, mst*(i+1) - min(p1,p2));
            
            }

            cout << ans << "\n";

        }
        else{
            cout << "-1\n";
        }

    }

    return 0;
}
