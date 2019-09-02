#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define vll vector<ll>
#define vll2(arr, n, m) vector<vll> arr(n, vll(m))
#define vll2v(arr, n, m, v) vector<vll> arr(n, vll(m, v))
#define ff first
#define ss second
#define pb push_back
#define all(arr) arr.begin(), arr.end()
#define ED cout<<endl;
#define D1(x) (cerr << #x << ": " << x << " ")
#define D2(x, y) (cerr << #x << ": " << x << ", " << #y << ": " << y << " ")
#define D3(x, y, z) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << " " )
#define D4(x, y, z, a) (cerr << #x << ": " << x << ", " << #y << ": " << y << ", " << #z << ": " << z << ", " << #a << ": " << a << " " )
#define D1e(x) (D1(x) << endl)
#define D2e(x, y) (D2(x,y) << endl)
#define D3e(x, y, z) (D3(x,y,z) << endl)
#define D4e(x, y, z, a) (D4(x,y,z,a) << endl)
#define Dsp cerr << " ||  ";
#define Dspe cerr << " || "<< endl;
#define DA(arr, n) for(ll i=0; i<n; i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DvA(arr) for(ll i=0; i<arr.size(); i++) cerr << "(" << i << ", " << arr[i] << "),  "; cerr<< endl;
#define DAu(arr) for(auto x: arr) cerr << x << " " ; cerr<< endl;
#define maxvA(arr) arr[max_element(all(arr)) - arr.begin()]
#define minvA(arr) arr[min_element(all(arr)) - arr.begin()]
#define maxA(arr, n) arr[max_element(arr, arr+n) - arr]
#define minA(arr, n) arr[min_element(arr, arr+n) - arr]

#define Fi(i, L, R) for (ll i = (L); i < (R); i++)
#define F(L, R) for (ll i = (L); i < (R); i++)
#define F0(R) F(0,R)
#define F1(R) F(1,R)
#define FEi(i, L, R) for (ll i = (L); i <=(R); i++)
#define FE(L, R) for (ll i = (L); i <=(R); i++)
#define FE0(R) FE(0,R)
#define FE1(R) FE(1,R)
#define FR(L, R) for (ll i = L; i > R; i--)
#define FRE(L, R) for (ll i = L; i >= R; i--)

using namespace std;

const double EPS = 1e-9;
const ll MOD = (1e9) + 7;
const int INF = 1000000005;
const ll INFF = 1000000000000000005LL;
const double PI = acos(-1);
const int M8 = 1e8; // int
// int
const int M7 = 1e7; // ll
const int M6 = 1e6;
const int M5 = 1e5;
const int dx[4][2] = {{0,  1},
                      {0,  -1},
                      {1,  0},
                      {-1, 0}};
const int dxx[8][2] = {{0,  1},
                       {0,  -1},
                       {1,  0},
                       {-1, 0},
                       {1,  1},
                       {1,  -1},
                       {-1, 1},
                       {-1, -1}};


const int M9 = 1e6;
bool mx[M9];

void sieveOfEratosthenes(int N, int s[])
{
    // Create a boolean array "prime[0..n]" and
    // initialize all entries in it as false.
    vector <bool> prime(N+1, false);

    // Initializing smallest factor equal to 2
    // for all the even numbers
    for (int i=2; i<=N; i+=2)
        s[i] = 2;

    // For odd numbers less then equal to n
    for (int i=3; i<=N; i+=2)
    {
        if (prime[i] == false)
        {
            // s(i) for a prime is the number itself
            s[i] = i;

            // For all multiples of current prime number
            for (int j=i; j*i<=N; j+=2)
            {
                if (prime[i*j] == false)
                {
                    prime[i*j] = true;

                    // i is the smallest prime factor for
                    // number "i*j".
                    s[i*j] = i;
                }
            }
        }
    }
}

void generatePrimeFactors(int N)
{
    // s[i] is going to store smallest prime factor
    // of i.
    int s[N+1];

    // Filling values in s[] using sieve
    sieveOfEratosthenes(N, s);

    printf("Factor Power\n");

    int curr = s[N];  // Current prime factor of N
    int cnt = 1;   // Power of current prime factor

    // Printing prime factors and their powers
    while (N > 1)
    {
        N /= s[N];

        // N is now N/s[N].  If new N als has smallest
        // prime factor as curr, increment power
        if (curr == s[N])
        {
            cnt++;
            continue;
        }

        printf("%d\t%d\n", curr, cnt);

        // Update current prime factor as s[N] and
        // initializing count as 1.
        curr = s[N];
        cnt = 1;
    }
}



bool isok(int i) {

    int sq = ceil(sqrt(i));
    int od = 0, ev = 0;
    for (int j = 1; j <= sq; j++) {
        if (i % j == 0) {

            if (j % 2) {
                od++;
            } else {
                ev++;
            }
            int p2 = i / j;
            if (p2 % 2) {
                od++;
            } else {
                ev++;
            }
        }
    }
    return abs(od - ev) <= 2;
}

void factor() {

    for (int i = 0; i <= M9; i++) {

        if (isok(i))
            mx[i] = 1;
        else
            mx[i] = 0;

    }
}

void solve(int t) {

    int ans = 0;
    int l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++) {

        if (i > M9) {
            if(isok(i)){
                ans++;
            }
        } else {
            if (mx[i])
                ans++;
        }
    }
    cout << "Case #" << t << ": " << ans << "\n";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

//    factor();

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i);
    }


    return 0;
}



