#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("./input", "r", stdin);
    ll y,b,r;
    cin >> y >> b >> r;

    y+=2;
    b+=1;

    ll mm = min(y, min(b,r));
    if(mm == r){
        cout << r-2 + r-1 + r << endl;
    }
    else if(mm == b){
        b -=1;
        cout << b-1 +  b + b+1 << endl;
    }
    else{
        y -=2;
        cout << y + y+1 + y+2 << endl;
    }

    return 0;
}
