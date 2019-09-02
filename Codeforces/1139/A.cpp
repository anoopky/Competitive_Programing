#include<bits/stdc++.h>


using namespace std;

#define ll long long int

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll cc = 0;
    ll ans =0;
    for(ll i=0; i<n; i++){
        int val = s[i] - '0';

        if(val %2 ==0){
         ans +=1;
         ans +=cc;
        }
        cc++;
    }

    cout << ans;
    return 0;
}
