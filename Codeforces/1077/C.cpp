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

ll arr[1000007];
unordered_map<ll, ll> mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n;
    cin >> n;
    ll sum =0;
    for(ll i=0; i<n; i++){
        cin >> arr[i];
        if(mp.find(arr[i]) == mp.end())
            mp[arr[i]] = 1;
        else
            mp[arr[i]]++;
        sum +=arr[i];
    }
    vector<ll> ans;
    for(ll i=0; i<n; i++){
        ll ts = sum-arr[i];
        if(ts%2 == 0 && mp.find(ts/2) != mp.end()){
            if(!((ts/2) == arr[i] && mp[ts/2] == 1))
                ans.pb(i+1);
        }
    }

    cout << ans.size() << "\n";
    for(auto x: ans)
        cout << x << " ";
    cout << "\n";

    return 0;
}
