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
const int M8 = 1e8; // int
const int M7 = 1e7; // ll
const int M6 = 1e6;
const int M5 = 1e5;
const int dx[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
const int dxx[8][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll d1,d2,m1,m2;
    string s,s1,s2,s3;
    cin >> s1;
    cin >> s2;

    string ds1,ds2,ms1,ms2;
    ds1 = s1.substr(0, 2);
    ms1 = s1.substr(3, 4);
    ds2 = s2.substr(0, 2);
    ms2 = s2.substr(3, 4);

    d1 = stoi(ds1);
    d2 = stoi(ds2);
    m1 = stoi(ms1);
    m2 = stoi(ms2);
    float D = (d1+d2)/2.0;
    ll D1 = (d1+d2)/2;
    ll M = (m1+m2)/2;

    float val = ((D-D1)*60.0) + M;
    ll v1 = (val);
    D1 += v1/60;
    v1 %=60;
    string a1,a2;
    string z = "0";
    a1 = to_string(D1);
    a2 = to_string(v1);
    if(D1 <= 9)
        a1 = z+a1;
    if(v1 <=9 )
        a2 = z+a2;
    cout << a1 << ":" << a2;
    return 0;
}
