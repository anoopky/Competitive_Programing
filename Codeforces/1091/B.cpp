#include <bits/stdc++.h>
#define ll long long int
#define ff first
#define ss second
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("./input", "r", stdin);
    ll n;
    cin >> n;
    ll tx=0, ty=0;
    for (ll i = 0; i < n; ++i) {
        ll x,y;
        cin >> x >>y;
        tx+=x;
        ty+=y;
    }

    for (ll i = 0; i < n; ++i) {
        ll x,y;
        cin >> x >>y;
        tx+=x;
        ty+=y;
    }

    cout << tx/n << " " << ty/n << endl;


    return 0;
}
