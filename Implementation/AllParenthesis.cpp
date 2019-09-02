#include <bits/stdc++.h>

using namespace std;


void print(vector<char> str) {

    for (int i = 0; i < str.size(); i++)
        cout << str[i];

    cout << "\n";
}

void generate(int i, vector<char> &str, int n, int o, int c) {


    if (i == n) {
        print(str);
        return;
    }

    if (o > c) {
        str[i] = ')';
        generate(i + 1, str, n, o , c+1 );
    }

    if(o < n/2) {
        str[i] = '(';
        generate(i + 1, str, n, o+1, c);
    }

}

int main() {


    int n = 8;

    vector<char> str(n);

    generate(0, str, n, 0, 0);

    return 0;
}