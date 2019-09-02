#include <bits/stdc++.h>
#define ll long long int

using namespace std;
//ll arr[100000000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("./input", "r", stdin);
    map<ll, bool> mp;
    ll n;
    cin >> n;
    mp[1] = 1;
    for(ll d=1; d<=(n/2); d++){
        double nth = floor(((n-1)/(d*1.0)) +1);
        double sum1 = (nth/2.0)*((2+(nth-1)*d)*1.0);
        ll sum = (ll) sum1;
        cout << nth <<" "<< d << " " << sum1 << "  \n";
        if(mp.find(sum) == mp.end()){
            mp[sum] = 1;
        }

    }

    for(auto x: mp){
        cout << x.first << " ";
    }
    cout << endl;

    return 0;
}
