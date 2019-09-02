#include <bits/stdc++.h>

using namespace std;

int build(vector<int> A, int s, int e, vector<int> &S, int i) {

    if (s == e) {
        S[i] = A[s];
        return A[s];
    }

    int md = (s + e) / 2;
    S[i] = build(A, s, md, S, i * 2 + 1) + build(A, md + 1, e, S, i * 2 + 2);
    return S[i];
}

int query(vector<int> S, int s, int e, int ss, int ee, int i) {

    if (ss <= s && ee >= e) {
        return S[i];
    } else if (ee < s || e < ss) {
        return 0;
    }
    int md = (s + e) / 2;
    return query(S, s, md, ss, ee, i * 2 + 1) + query(S, md + 1, e, ss, ee, i * 2 + 2);
}

int updateSeg(vector<int> &S, int s, int e, int ss, int ee, int i, int val) {


    if (s == e) {
        S[i] += val;
        return S[i];
    }

    if (ee < s || ss > e) {
        return S[i];
    }


    int md = (s + e) / 2;
    S[i] = updateSeg(S, s, md, ss, ee, i * 2 + 1, val)
           + updateSeg(S, md + 1, e, ss, ee, i * 2 + 2, val);
    return S[i];
}

void updateSin(vector<int> &S, int s, int e, int ind, int i, int val) {

    if (ind < s || ind > e) {
        return;
    }

    S[i] += val;
    if (s != e) {
        int md = (s + e) / 2;

        updateSin(S, s, md, ind, i * 2 + 1, val);
        updateSin(S, md + 1, e, ind, i * 2 + 2, val);
    }

}


int main() {

    vector<int> A = {1, 3, 5, 7, 9, 11};
    int n = A.size();
    vector<int> S(4 * n, 0);
    build(A, 0, n - 1, S, 0);

    int nn = S.size();

    for (int i = 0; i < nn; i++) {
        cout << S[i] << " ";
    }
    cout << "\n";

    cout << query(S, 0, n - 1, 0, 1, 0) << "\n";
    cout << query(S, 0, n - 1, 2, 4, 0) << "\n";
    updateSeg(S, 0, n - 1, 2, 4, 0, 2);
//    updateSin(S, 0, n - 1, 0, 0, 10);
    cout << query(S, 0, n - 1, 2, 4, 0) << "\n";
    return 0;
}
