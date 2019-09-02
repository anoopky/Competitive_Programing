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


tuple<ll, ll, ll>  build_tree(vector<tuple<ll, ll, ll>> &tree, ll s, ll e, ll n, ll i, string str){

//    D3e(s,e,i);
    if(s == e){
        tree[i] = {0, str[s] == '(' ? 1 : 0, str[s] == ')' ? 1 : 0};
        return tree[i];
    }

    ll mid = (s+e)/2;
    tuple<ll, ll, ll> t1 = build_tree(tree, s, mid, n, i*2+1, str);
    tuple<ll, ll, ll> t2 = build_tree(tree, mid+1, e, n, i*2+2, str);
    ll p,o,c;
    ll p1,o1,c1;
    tie(p,o,c) = t1;
    tie(p1,o1,c1) = t2;
    ll min_match = min(o,c1);
    ll pair = p+p1+min_match;
    ll open = o+o1-min_match;
    ll close = c+c1-min_match;
    tree[i] = {pair, open, close};
    return tree[i];

}


tuple<ll, ll, ll>  query(vector<tuple<ll, ll, ll>> &tree, ll s, ll e, ll n, ll i, string str, ll qs, ll qe){

//    D3e(s,e,i);

    if(qs > e || qe < s ){
        return tree[i];
    }
    if(s == e){
//        D3e(s,e,i);
        tree[i] = {0, str[s] == '(' ? 0 : 1, str[s] == ')' ? 0 : 1};
        return tree[i];
    }

    ll mid = (s+e)/2;
    tuple<ll, ll, ll> t1 = query(tree, s, mid, n, i*2+1, str, qs, qe);
    tuple<ll, ll, ll> t2 = query(tree, mid+1, e, n, i*2+2, str, qs, qe);
    ll p,o,c;
    ll p1,o1,c1;
    tie(p,o,c) = t1;
    tie(p1,o1,c1) = t2;
    ll min_match = min(o,c1);
    ll pair = p+p1+min_match;
    ll open = o+o1-min_match;
    ll close = c+c1-min_match;
    tree[i] = {pair, open, close};
    return tree[i];

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("./input", "r", stdin);
    ll n;
    cin >> n;
    string str;
    cin >> str;
    vector<tuple<ll, ll, ll>> tree(4*n+1);
    build_tree(tree, 0, n-1, n-1, 0, str);
    ll ans =0;
    for(ll i=0; i<n; i++){

        vector<tuple<ll, ll, ll>> tmp(tree);
        tuple<ll, ll, ll > t = query(tmp, 0, n-1, n-1, 0, str, i, i);
        ll p,o,c;
        tie(p,o,c) = t;
        if(!o && !c)
            ans++;
        D4e(p,o,c, i);
    }
    cout << ans << "\n";
    return 0;
}
