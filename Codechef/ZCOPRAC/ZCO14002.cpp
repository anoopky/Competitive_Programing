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
    for(ll i=0; i<n; i++)
        cin >> arr[i];



    ll ans =0;
    if(n<=2){

        ll mn = min_element(arr, arr+n) -arr;
        cout << arr[mn] << "\n";
        return 0;

    }
    ll dp[n];

    dp[0] = arr[0];
    dp[1] = arr[1];
    dp[2] = arr[2];

    for(ll i=3; i<n; i++){
        dp[i] = arr[i] + min(dp[i-3], min(dp[i-2], dp[i-1]));
    }

//    for(ll i =0; i<n; i++){
//        cout << dp[i] << "\n";
//    }
//    cout << ans << "\n";
    cout << min(dp[n-3], min(dp[n-2], dp[n-1])) << "\n";

    return 0;
}

