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
const int MAX8 = 1e8; // int
const int MAX7 = 1e7; // ll
const int MAX6 = 1e6;
const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
//    freopen("./out", "w", stdout);
#endif

    ll t;
    cin >> t;
    vector<bool> prime(MAX6,1);
    prime[0] = prime[1] = 0;
    for(ll i=2; i*i<MAX6; i++){
        if(prime[i]){
            for(ll j=i*2; j<MAX6; j+=i){
                prime[j] = 0;
            }
        }
    }
    vll pr;
    F0(MAX6){
        if(prime[i])
            pr.pb(i);
    }

//    for(ll i=0; i<100; i++)
//        cout << pr[i],ED;

    while(t--){
        ll n;
        cin >> n;
        if(n == 3){
            cout << "6 10 15\n";
            continue;
        }
        if(n == 4){
            cout << "374 595 1365 858\n";
            continue;
        }
        ll prev = pr[0];
        ll safe = 1;
        vll ans(n);
        ans[0] = 7*5;
        ans[1] = 11*7;
        ans[2] = 2*11;
        ans[3] = 2*13;

        ll cc = 0;
        ll od = 1;
        ll prind = 5;
        Fi(i,4,n){

            if(od%2 == 0){
                ans[i] = 2*pr[prind];
                safe = prind;
                cc++;
                if(cc == 1)
                    prind++;
                if(cc == 2){
                    od = 1;
                    cc = 0;
                }
            }
            else{
                ans[i] = 3*pr[prind];
                safe = prind;
                cc++;
                if(cc == 1)
                    prind++;
                if(cc == 2){
                    od = 0;
                    cc = 0;
                }
            }
        }

        ans[n-1] *= 5;

        for(auto x: ans){
            cout << x << " ";
        }
        ED;
    }


    return 0;
}
