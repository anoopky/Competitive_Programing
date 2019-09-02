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
ll mx = 1000000;
vector<bool> prime(mx, 1);
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    prime[0] = prime[1] =0;
    for(ll i=2; i*i<mx; i++){
        if(prime[i]){
            for(ll j = i*2; j<mx; j+=i)
                prime[j] = 0;
        }
    }

//    for(ll i=0; i<20; i++){
//        cout << prime[i] << endl;
//    }
    ll n;
    cin >> n;
    ll ans =0;
//    string s = "12";
//    cout << s << endl;

    for(ll i=2; i<n; i++){
        string s = to_string(i);
        ll f = 1;
        for(ll i=0; i<s.length(); i++){
            ll ch = stoi(s);
            if(!prime[ch] || ch >= n){
                f = 0;
                break;
            }
            rotate(s.begin(), s.begin() + 1, s.end());

        }

        if(f == 1){
            ans += i;
        }
    }

    cout << ans << "\n";

    return 0;
}
