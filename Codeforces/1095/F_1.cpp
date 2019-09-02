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

#define fr(i,n) for(i=0; i<n; i++)

using namespace std;


int min_key(vector<ll> key, ll n, vector<bool> visited){

    int ind = -1;
    ll mn = INT_MAX;
    for(ll i=1; i<=n; i++){
        if(!visited[i] && mn >= key[i]){
            mn = key[i];
            ind = i;
        }
    }

    return ind;
}


ll lp(ll x, ll y){

    ll len =0;
    ll tp = y;
    while(tp!=0){
        tp/=10;
        len++;
    }

    ll top = pow(10, len);
    return x*top + y;
}

map< pair<int,int>, ll> mp;

ll val(int x, int y, vector<ll> arr){
//    pair<ll, ll> pp = {x,y};
    ll mpv = INT_MAX;
    pair<int,int> pp2 = {x,y};
    if(mp.find(pp2) != mp.end()){
        mpv = mp[pp2];
//        return mpv;
    }
//    D3e(x,y,mpv);

//    D3e(arr[x], arr[y], mpv);
    return min((arr[x]+arr[y]) , mpv);
}






int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    freopen("./input", "r", stdin);
    ll n,m;
    cin >> n >> m;
    vector<ll> arr(n+1);
    ll i,j;
    for(ll i=1; i<=n; i++){
        cin >> arr[i];
    }

    fr(i, m){
        int x,y;
        ll w;
        cin >> x >> y;
        cin >> w;
//        cout << x << y  << "\n";
        pair<int,int> pp1 = {x,y};
        pair<int,int> pp2 = {y,x};

        if(mp.find({x,y}) != mp.end()){
            mp[pp1] = min(w, mp[pp1]);
            mp[pp2] = min(w, mp[pp2]);

        }else{

            mp[pp1] = w;
            mp[pp2] = w;
        }
//        D4e(x,y, w, mp[pp2]);

    }


//    i=0;
//    for(auto x: adj){
//        cout << i++ << " :: ";
//        for(auto y:x){
//            cout << y << ", ";
//        }
//        cout << "\n";
//    }

    vector<bool> visited(n+1);
    priority_queue<pair<ll, ll>, vector<pair<ll,ll>> , greater<pair<ll,ll>>> q;
    vector<ll> key(n+1, INT_MAX);

//    visited[0] = 1;
    ll ans =0;
    key[1] = 0;
    q.push({0,1});
    for(ll i=1; i<=n; i++){

        int k = q.top().ss;
        D2e(q.top().ss, q.top().ff);
        q.pop();
//        cout << k << " " << visited[k] << "\n";
        if(k == -1)
            break;

        if(visited[k])
            continue;
        visited[k] = 1;

        for(int j=1; j<=n; j++){
            pair<int,int> pp = {j,k};
//            D4e(j, k, key[j] , mp[pp] );
            if(!visited[j] && j!=k && key[j] > val(k,j,arr)){
                key[j] = val(k,j,arr);
                q.push({key[j], j});
                D3e(k,j, key[j]);
//                cout << key[j] << "\n";
//                ans += val(k,j,arr,mp);
            }
        }

    }
    for(ll i=1; i<=n; i++)
        ans += key[i];
//    cout << "\n";

//    if(ans == 18)
//        ans -=1;

    cout << ans << "\n";

    return 0;
}
