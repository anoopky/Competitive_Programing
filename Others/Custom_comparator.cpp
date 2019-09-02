#include<bits/stdc++.h>

using namespace std;

struct cmpr{

    bool operator()(pair<int,int> l, pair<int,int> r){
    
        return l.second < r.second;
    
    }


}cmp;


struct cmpr1{

    bool operator()(int l, int r){
        return r < l;
    }

}cmp1;

int main(){
    
    vector<pair<int,int>> arr;
    arr.push_back({1,8});
    arr.push_back({2,4});
    arr.push_back({3,1});

    sort(arr.begin(), arr.end(), cmp);

    for(int i=0; i<arr.size(); i++){
        cout << arr[i].first << " " << arr[i].second << "\n";
    }
    vector<int> ar1;
    ar1.push_back(1);
    ar1.push_back(2);
    ar1.push_back(3);
    sort(ar1.begin(), ar1.end(), cmp1);

    for(int i=0; i<ar1.size(); i++){
        cout << ar1[i] << "\n";
    }
    
    return 0;

}
