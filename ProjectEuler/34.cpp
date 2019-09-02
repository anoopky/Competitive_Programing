#include <bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define D1(x) (cerr << #x << ": " << x << " ")
#define D2(x,y) (cerr << #x << ": " << x << ", " << #y << ": " << y << " ")
#define D3(x,y,z) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << " " )
#define D1e(x) (D1(x) << endl)
#define D2e(x,y) (D2(x,y) << endl)
#define D3e(x,y,z) (D2(x,y,z) << endl)
#define Dsp cerr << " ||  ";
#define Dspe cerr << " || "<< endl;

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<ll> fac(10);
    fac[0] = 1;
    for(ll i=1; i<=9; i++){
        fac[i] = fac[i-1]*i;
    }
//    for(ll i=1; i<=9; i++){
//        cout << fac[i] << "\n";
//    }

    //    freopen("./input", "r", stdin);
    ll n;
    cin >> n;
    ll fa =0;
    for(ll i=11; i<n; i++){
        ll tp = i;
        ll ans =0;
        while(tp!=0){
            ll rem = tp%10;
            ans += fac[rem];
            tp/=10;
        }
        if(ans%i == 0){
            fa +=i;
        }
    }

    cout << fa << "\n";


    return 0;
}
