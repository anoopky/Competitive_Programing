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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n;
    cin >> n;
    ll arr[n];
    ll sum[n];
    for(ll i=0; i<n; i++){
        ll x;
        cin >> x;
        arr[i] = x;

    }
    sum[0] = arr[0];
    for(ll i=1; i<n; i++)
        sum[i] = sum[i-1]+arr[i];

    for(ll i=0; i<n-1; i++){
        arr[i] = arr[i]+arr[i+1];
    }

    for(ll i=0; i<n-2; i++){

        for(ll j =0; j<n-2-i; j++){
            D3e(i,j,arr[i]);
            if(i%2 ==0 ){
                arr[j] = max(arr[j], arr[j+1]);
            }
            else{
                ll intersec = 0;
                intersec = sum[i+2-1] - sum[j];
                arr[j] = max(max(arr[j], arr[j+1]), arr[j]+arr[j+1]-intersec);
            }
        }

        continue;
    }

    cout << max(arr[0], arr[1]) << "\n";

    return 0;
}
