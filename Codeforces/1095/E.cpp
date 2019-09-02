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

using namespace std;


ll f1(ll n, string s){
    vector<ll> arr(n+1);
    vector<ll> mn(n+1);
    for(ll i=1; i<=n; i++){
        if(s[i-1] == '(')
            arr[i] = arr[i-1]+1;
        else
            arr[i] = arr[i-1]-1;
    }

    if(arr[n]!=2)
        return 0;
    mn[n] = arr[n];
    for(ll i=n-1; i>=1; i--){
        mn[i] = min(mn[i+1], arr[i]);
    }

    ll tp =0, res=0;
    for(ll i=1; i<=n; i++){

        if(tp >=0 && s[i-1] == '(' && mn[i] >=2)
            res++;
        tp = min(tp, arr[i]);
    }

    return res;

}

ll f2(ll n, string s){
    vector<ll> arr(n+1);
    vector<ll> mn(n+1);
    if(s[n-1]== ')')
        arr[n] = 1;
    else
        arr[n] = 0;
    for(ll i = n-1; i>=1; i--){
        if(s[i-1] ==  ')')
            arr[i] = arr[i+1] +1;
        else
            arr[i] = arr[i+1]-1;
    }
    if(arr[1] !=2)
        return 0;
    mn[1] = arr[1];
    for(ll i = 2; i<=n; i++)
        mn[i] = min(mn[i-1], arr[i]);

    ll res =0, tp =0;
    for(ll i=n; i>=1; i--){

        if(tp >=0 && s[i-1] == ')' && mn[i] >=2)
            res++;
        tp = min(tp, arr[i]);
    }
    return res;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("./input", "r", stdin);
    ll n;
    cin >> n;
    string s;
    cin >> s;

    if(n%2 != 0){
        cout << 0 << "\n";
    }
    else{
        cout << f1(n,s) + f2(n,s);
    }

    return 0;
}
