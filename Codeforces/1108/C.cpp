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

    ll n;
    cin >> n;
    string s;
    cin >> s;


   if(n <3){
       cout << "0\n";
       cout << s << "\n";
       return 0;
   }

   if(n == 3){
       ll cc=0;
       if(s[0] == 'R'){
           if(s[1] == 'R'){
               cc++;
               s[1] = (s[2] == 'B'? (s[1] = 'G') :  (s[1] = 'B') );
           }
           if(s[2] == 'R'){
               cc++;
               s[2] = (s[1] == 'B'? (s[2] = 'G') :  (s[2] = 'B') );
           }

       }

       if(s[0] == 'B'){

           if(s[1] == 'B'){
               cc++;
               s[1] = (s[2] == 'R'? (s[1] = 'G') :  (s[1] = 'R') );
           }

           if(s[2] == 'B'){
               cc++;
               s[2] = (s[1] == 'R'? (s[2] = 'G') :  (s[2] = 'R') );
           }

       }

       if(s[0] == 'G'){


           if(s[1] == 'G'){
               cc++;
               s[1] = (s[2] == 'R'? (s[1] = 'B') :  (s[1] = 'R') );
           }

           if(s[2] == 'G'){
               cc++;
               s[2] = (s[1] == 'R'? (s[2] = 'B') :  (s[2] = 'R') );
           }
       }

       cout << cc << "\n";
       cout << s << "\n";
       return 0;
   }
    char st1,st2,st3;
    ll mx1 =0;
    ll v1 = 0, v2=0, v3=0;
    for(ll j =0; j<3; j++){
        char ck ;
        if(j == 0)
            ck = 'R';
        if(j == 1)
            ck = 'B';
        if(j == 2)
            ck = 'G';
        ll cc = 0;
        ll cc1 = 0;
        for(ll i =0; i<n; i+=3){
            if(s[i] == ck)
                cc++;
            if(s[i] != ck)
                cc1++;
        }

        if(cc > mx1){
            st1 = ck;
            v1 = cc1;
        }


    }

    mx1 =0;
    for(ll j =0; j<3; j++){
        char ck ;
        if(j == 0)
            ck = 'R';
        if(j == 1)
            ck = 'B';
        if(j == 2)
            ck = 'G';
        ll cc = 0;
        ll cc1 = 0;

        if(ck == st1)
            continue;
        for(ll i =1; i<n; i+=3){
            if(s[i] == ck)
                cc++;
            if(s[i] != ck)
                cc1++;
        }

        if(cc > mx1){
            st2 = ck;
            v2 = cc1;
        }

    }

    mx1 =0;

    for(ll j =0; j<3; j++){
        char ck ;
        if(j == 0)
            ck = 'R';
        if(j == 1)
            ck = 'B';
        if(j == 2)
            ck = 'G';
        ll cc = 0;
        ll cc1 = 0;

        if(ck == st1 || ck == st2)
            continue;
        for(ll i =2; i<n; i+=3){
            if(s[i] == ck)
                cc++;
            if(s[i] != ck)
                cc1++;
        }

        if(cc > mx1){
            st3 = ck;
            v3 = cc1;
        }

    }


    cout << v1 + v2 +v3 << "\n";

    for(ll i=0; i<n; i++){

        if(i%3 == 0){
            cout << st1;
        }
        if(i%3 == 1){
            cout << st2;

        }
        if(i%3 == 2)
            cout << st3;

    }


    return 0;
}
