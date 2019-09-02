#include <bits/stdc++.h>

using namespace std;


int build(vector<int> A, vector<int> &S, int s, int e, int i) {

    if (s == e) {
        S[i] = A[s];
        return S[i];
    }

    int md = (s + e) / 2;
    S[i] = build(A, S, s, md, i * 2 + 1) + build(A, S, md + 1, e, i * 2 + 2);
    return S[i];
}


int updateRange(vector<int> &S, vector<int> &L, int s, int e, int ss, int ee, int i, int val) {


    if (L[i] != 0) {

        S[i] += (e - s + 1) * L[i];

        if (s != e) {
            L[i * 2 + 1] += L[i];
            L[i * 2 + 2] += L[i];
        }
        L[i] = 0;
    }

    if (ss <= s && e <= ee) {


        S[i] += ((e - s) + 1) * val;

        if (s != e) {
            L[i * 2 + 1] += val;
            L[i * 2 + 2] += val;
        }

        return S[i];

    }

    if (ee < s || ss > e) {
        return S[i];
    }

    int md = (s + e) / 2;
    S[i] = updateRange(S, L, s, md, ss, ee, i * 2 + 1, val)
           + updateRange(S, L, md + 1, e, ss, ee, i * 2 + 2, val);

    return S[i];

}

int query(vector<int> &S, vector<int> &L, int s, int e, int ss, int ee, int i) {

    if (L[i] != 0) {

        S[i] += (e - s + 1) * L[i];

        if (s != e) {
            L[i * 2 + 1] += L[i];
            L[i * 2 + 2] += L[i];
        }

        L[i] = 0;

    }

    if (ss <= s && e <= ee) {
        return S[i];
    }

    if (ee < s || ss > e) {
        return 0;
    }

    int md = (s + e) / 2;
    return query(S, L, s, md, ss, ee, i * 2 + 1) + query(S, L, md + 1, e, ss, ee, i * 2 + 2);

}


int main() {

    vector<int> A = {1, 3, 5, 7, 9, 11};

    int n = A.size();
    vector<int> S(4 * n, 0);
    vector<int> L(4 * n, 0);

    for (int i = 0; i < n; i++) {
        build(A, S, 0, n - 1, 0);
    }

    int nn = S.size();
    for (int i = 0; i < nn; i++) {
        cout << S[i] << " ";
    }

    cout << "\n";

    updateRange(S, L, 0, n - 1, 0, 4, 0, 2);


    for (int i = 0; i < nn; i++) {
        cout << "(" << S[i] << "-" << L[i] << ") ";
    }
    cout << "\n";


    cout << query(S, L, 0, n - 1, 2, 4, 0) << "\n";

    for (int i = 0; i < nn; i++) {
        cout << "(" << S[i] << "-" << L[i] << ") ";
    }
    cout << "\n";
    return 0;
}
