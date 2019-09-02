#include <bits/stdc++.h>
#define ll long long int
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

ll arr[50][50];

void ans(ll n, ll m, int cc){

    cout << cc; ED;
    F0(n){
        Fi(j,0,m){
            cout << arr[i][j] << " ";
        }
        ED;
    }
}

void ans1(vector<vll> arr1, ll n, ll m, int cc){

    cout << cc; ED;
    F0(n){
        Fi(j,0,m){
            cout << arr1[i][j] << " ";
        }
        ED;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    ll t;
    cin >> t;

    ll r1[4] = {1,2,3,3};
    F0(50){
        arr[0][i] = r1[i%4];
    }
    ll tt[4][4] = {{1,2,3,3}, {1,4,4,2}, {3,3,1,2}, {4,2,1,4}};

    F1(50){
        Fi(j,0,50){
            arr[i][j] = tt[i%4][j%4];
        }
    }

    while(t--){

        ll n,m;
        cin >> n >> m;

        if( min(m,n) >=3){
            ans( n,m,  4);

        }
        else{

            if(n == 1 && m == 1){
                vll2(arr1,1,1);
                arr1[0][0] = 1;
                ans1(arr1, n,m, 1);

            }
            else if(n == 2 && m == 2){
                vll2(arr1,2,2);
                arr1[0][0] = 1;
                arr1[0][1] = 1;
                arr1[1][0] = 2;
                arr1[1][1] = 2;
                ans1(arr1,n,m, 2);

            }
            else if(m == 1){
                vll2(arr1,n,1);
                ll t1[] = {1,1,2,2};
                F0(n){
                    arr1[i][0] = t1[i%4];
                }
                ans1(arr1,n,m,n >=3? 2 : 1);

            }
            else if(n == 1){
                vll2(arr1,1,m);
                ll t1[] = {1,1,2,2};
                F0(m){
                    arr1[0][i] = t1[i%4];
                }
                ans1(arr1,n,m, m >=3? 2 : 1);

            }
            else if(n == 2){
                vll2(arr1,2,m);

                ll t1[] = {1,2,3};
                F0(m){
                    arr1[0][i] = t1[i%3];
                }F0(m){
                    arr1[1][i] = t1[i%3];
                }
                ans1(arr1,n,m,3);

            }
            else if(m == 2){
                vll2(arr1,n,2);

                ll t1[] = {1,2,3};
                F0(n){
                    arr1[i][0] = t1[i%3];
                }F0(n){
                    arr1[i][1] = t1[i%3];
                }
                ans1(arr1,n,m,3);

            }
        }

    }


    return 0;
}
