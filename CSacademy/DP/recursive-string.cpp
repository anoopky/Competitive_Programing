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

ll ans[36];

string f(int N, ll k) {

    if (N == 0) return "a";
    if (N == 1) return "b";
    if (N == 2) return "c";
    if(k >= 0 && k < ans[N-1]){
        return f(N-1, k);
    }
    else if(k >=ans[N-1] && k < ans[N-1]+ans[N-2]){
        return f(N-2, k - ans[N-1]);

    }
    else{
        return f(N-3, k-ans[N-1]-ans[N-2]);

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll n,k;
    cin >> n >> k;
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 1;
    for(ll i=3; i<36; i++){
        ans[i] = ans[i-3]+ans[i-2]+ans[i-1];
    }
    if(ans[n] < k)
        cout<< "-1";
    else
    cout << f(n, k-1) << "\n";

    return 0;
}
