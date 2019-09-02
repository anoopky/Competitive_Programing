#include<bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){
    
    ll n;
    cin >> n;
    vector<ll> one;
    vector<ll> two;
    ll t = 0;
    for(ll i=0; i<n; i++){
        ll x,y;
        cin >> x >> y;
        t += x;
        if(x == 1)
            one.push_back(y);
        else
            two.push_back(y);
    }
    
    sort(one.begin(), one.end(), greater<ll>());
    sort(two.begin(), two.end(), greater<ll>());
   
    //for(ll i=1; i<=t; i++){
        ll cst = 0;
        vector<ll> cst1;
        ll cnt = 1, j =0, k =0;
        for(; cnt <= t && j<one.size() && k < two.size();){
            
       // cout << cnt << " " << cst << " " << j << " " << k << " " << one[j] << " " << two[k] <<" \n";

            if(one[j] > two[k]){
                cst += one[j];
                cst1.push_back(cst);
                j++;
                cnt++;
            }
            else{
                if(cnt == 1){
                    cst += one[j];
                    cst1.push_back(cst);
                    j++;
                    cnt++;
                }
                else if((j+1) < one.size() && (cnt+2) <= t && one[j]+one[j+1] > two[k]){
                    cst += one[j];
                    cst1.push_back(cst);
                    cst += one[j+1];
                    cst1.push_back(cst);
                    j+=2;
                    cnt+=2;
                }
                else if(cnt+2 <= t){
                    cst += two[k];
                    cst1.push_back(cst);
                    k++;
                    cnt +=2;
                }
            }

        }

       // if(i == 15)
         //   break;
        while(cnt <= t && j < one.size()){
            cst+=one[j]; 
            cst1.push_back(cst);
            j++;
            cnt++;
        }

        while((cnt+2) <= t && k < two.size()){
            cst += two[k]; 
            cst1.push_back(cst);
            k++;
            cnt+=2;
        }

        for(ll i=0; i<cst1.size(); i++)
            cout <<cst1[i] << " ";
    //}
    
    return 0;
}
