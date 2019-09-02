

//{
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.


bool cmp(string a, string b){

    if(a+b > b+a)
        return 1;
    else
        return 0;

}
string findLargestNumber(vector<int> A)
{

    vector<string> res;
    for(int i=0; i<A.size(); i++)
        res.push_back(to_string(A[i]));

    sort(res.begin(), res.end(), cmp);
    string ans = "";
    for(int i=0; i<res.size(); i++){
        ans += res[i];
    }
    return ans;
}

int main() {

    vector<int> ans = {0,1};
    cout << findLargestNumber(ans) << "\n";
    return 0;
}
//}//
/*This is a function problem.You only need to complete the function given below*/
//User function Template for C++
/**
 * Params:
 * vector<pair<int,int>> points : All the points present in 2D space.
 * P : The source point from which K nearest neighbours need to be find in 2D plane.
 * K : Number of closest neighbours to be found.
 *
 * Return Type:
 * vector<pair<int,int>> : K Closest neighbours
 **/
