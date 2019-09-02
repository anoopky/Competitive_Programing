#include <bits/stdc++.h>
#define ll long long int

using namespace std;

ll arr[107];


bool solve(ll i, ll sum){

    if(sum == 0)
        return true;

    if(i<0 || sum < 0)
        return false;

    return solve(i-1, sum-arr[i]) || solve(i-1, sum);

}


int main(){

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif


    ll n;
    cin >> n;
    for(ll i=0; i<n; i++) cin >> arr[i];
    ll sum;
    cin >> sum;
    if(solve(n, sum)){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }


    bool dp[107][107];

    for(ll i=0; i<n; i++){
        dp[0][i] = 0;
    }
    for(ll i=0; i<=sum; i++){
        dp[i][0] = 1;
    }


    for(ll i=1; i<=n; i++){
        for(ll j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    }

    for(ll i=0; i<=n; i++){
        for(ll j=0; j<=sum; j++){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    if(dp[n][sum]){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
