#include<bits/stdc++.h>

using namespace std;
#define ll long long int

int main(){
    ll n;
    cin >> n;
    string s1,s2;
    cin >> s1;
    cin >> s2;
    vector<ll> q1[27];
    vector<ll> q2[27];

    for(ll i=0; i<n; i++){
        if(s1[i] == '?'){
            q1[27].push_back(i);
        }
        else{
            q1[s1[i]-'a'].push_back(i);
        }

        if(s2[i] == '?'){
            q2[27].push_back(i);
        }
        else{
            q2[s2[i]-'a'].push_back(i);
        }
    }

   
    return 0;
}
