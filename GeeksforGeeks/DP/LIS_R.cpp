#include <bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
#define pb push_back
#define D1(x) (cerr << #x << ": " << x << " ")
#define D2(x,y) (cerr << #x << ": " << x << ", " << #y << ": " << y << " ")
#define D3(x,y,z) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << " " )
#define D4(x,y,z,a) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << ", " << #a << ": " << a << " " )
#define D1e(x) (D1(x) << endl)
#define D2e(x,y) (D2(x,y) << endl)
#define D3e(x,y,z) (D3(x,y,z) << endl)
#define D4e(x,y,z,a) (D4(x,y,z,a) << endl)
#define Dsp cerr << " ||  ";
#define Dspe cerr << " || "<< endl;
#define Darr(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;

using namespace std;

int arr[1007];

ll solve(ll s, ll cc, ll n){
    if(s > n)
        return cc;
    ll c = cc;
    ll ck = arr[s];
    for(ll i=s+1; i<n; i++){
        if(arr[i] > ck){
            c = max(c, solve(i, cc+1, n));
        }
        else{
            c = max(c, solve(i, cc, n));
        }
    }

    return c;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll t;
    cin >> t;
    while(t-- !=0){

        ll n;
        cin >> n;
        for(ll i=0; i<n; i++){
            cin >> arr[i];
        }

        cout << solve(0, 1, n) << "\n";
    }

    return 0;
}
