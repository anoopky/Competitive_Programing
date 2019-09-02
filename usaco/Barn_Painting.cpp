#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define vll vector<ll>
#define vll2(arr,n,m) vector<vll> arr(n, vll(m))
#define vll2v(arr,n,m,v) vector<vll> arr(n, vll(m, v))
#define ff first
#define ss second
#define pb push_back
#define all(arr) arr.begin(), arr.end()
#define ED cout<<endl;
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
#define DA(arr,n) for(ll i=0; i<n; i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DvA(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DAu(arr) for(auto x: arr) cerr << x << " " ; cerr<< endl;
#define maxvA(arr) arr[max_element(all(arr)) - arr.begin()]
#define minvA(arr) arr[min_element(all(arr)) - arr.begin()]
#define maxA(arr,n) arr[max_element(arr, arr+n) - arr]
#define minA(arr,n) arr[min_element(arr, arr+n) - arr]

#define Fi(i,L,R) for (ll i = (L); i < (R); i++)
#define F(L,R) for (ll i = (L); i < (R); i++)
#define F0(R) F(0,R)
#define F1(R) F(1,R)
#define FEi(i,L,R) for (ll i = (L); i <=(R); i++)
#define FE(L,R) for (ll i = (L); i <=(R); i++)
#define FE0(R) FE(0,R)
#define FE1(R) FE(1,R)
#define FR(L,R) for (ll i = L; i > R; i--)
#define FRE(L,R) for (ll i = L; i >= R; i--)

using namespace std;

const double EPS = 1e-9;
const ll MOD = (1e9)+7;
const int INF = 1000000005;
const ll INFF = 1000000000000000005LL;
const double PI = acos(-1);
const int M8 = (1e8)+7;; // int
const int M7 = (1e7)+7;; // ll
const int M6 = (1e6)+7;;
const int M5 = (1e5)+7;;
const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};

vll adj[M5];
ll dp[M5][3];
vll arr(M5);

void dfs(ll parent, ll node){

    bool leaf = 0;
    ll v1 =1, v2=1, v3 =1;

    for(auto x: adj[node]){
        if(x != parent){
            dfs(node, x);
            leaf = 1;
            v1 *= (dp[x][1] + dp[x][2])%MOD;
            v1 =v1%MOD;
            v2 *= (dp[x][0] + dp[x][2])%MOD;
            v2 =v2%MOD;
            v3 *= (dp[x][1] + dp[x][0])%MOD;
            v3 =v3%MOD;

        }
    }

    if(!leaf) {
        if(arr[node] == 0){
            dp[node][0] = 1;
            dp[node][1] = 1;
            dp[node][2] = 1;
        }
        else{
            dp[node][arr[node]-1] = 1;
        }
    }
    else{
        if(arr[node] == 0) {
            dp[node][0] = v1;
            dp[node][1] = v2;
            dp[node][2] = v3;
        }
        else{
            if(arr[node]-1 == 0)
                dp[node][0] = v1;
            else if(arr[node]-1 == 1)
                dp[node][1] = v2;
            else if(arr[node]-1 == 2)
                dp[node][2] = v3;

        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ifstream cin("barnpainting.in");
    ofstream cout("barnpainting.out");
    ll n,k;
    cin >> n >> k;



    F0(n-1){
        ll x,y;
        cin >> x >>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    F0(k){
        ll x,y;
        cin >> x >> y;
        arr[x] = y;
    }


    dfs(-1, 1);

    cout << (dp[1][0] + dp[1][1] + dp[1][2])%MOD << "\n";
    return 0;
}
