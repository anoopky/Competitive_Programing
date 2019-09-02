#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
    
    ll t;
    cin >> t;

    while(t--){
        
        ll x,y,q;
        cin >> x >> y >> q;
        vector<ll> ar1,ar2;
        if(q == 0){
            cout << x * y << "\n";
            continue;
        }

        for(ll i=0; i<q; i++){
            
            ll m,n;
            cin >> m >> n;
            ar1.push_back(m);
            ar2.push_back(n);
        
        }

        sort(ar1.begin(), ar1.end());
        sort(ar2.begin(), ar2.end());

        ll dx = ar1[0], dy = ar2[0];
        for(ll i=1; i < q; i++){
        
            dx= max(dx, ar1[i] - ar1[i-1]);
            dy = max(dy, ar2[i] - ar2[i-1]);
        
        }
        
        dx = max(dx, x+1-ar1[q-1]);
        dy = max(dy, y+1-ar2[q-1]);

        cout << (dx-1) * (dy -1) << "\n";

    }
    

    return 0;
}
