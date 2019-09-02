#include <bits/stdc++.h>
using namespace std;

#define ll long long int

class BST{
public:
    int val;
    BST *left;
    BST *right;
    BST(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

BST * insert(BST *root, int val){

    if(root == NULL){

        BST *tp = new BST(val);
        return tp;
    }
    if(root->val < val){
        root->right = insert(root->right, val);
    }
    if(root->val > val){
        root->left = insert(root->left, val);
    }

    return root;
}

BST * createTree(){

    int n;
    cin >> n;
    BST *root = NULL;
    for(int i=0; i<n; i++){
        int val;
        cin >> val;
        root = insert(root, val);
    }

    return root;
}

ll solve(BST *root, ll &turn){

    if(root->left == NULL &&  root->right == NULL){
        cout << root->val << " " << turn<< "\n";
        if(turn %2 ==0){

            turn++;
            return (ll) root->val;
        }
        else{
            turn++;
            return 0;
        }

    }

    if(root->left != NULL &&  root->right != NULL){
        return solve(root->left, turn) + solve(root->right, turn);
    }
    if(root->right == NULL)
        return solve(root->left, turn);
    if(root->left == NULL)
        return solve(root->right, turn);

    return 0;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
#endif

    int t;
    cin >> t;
    BST *root = NULL;
    while(t--){
        root = NULL;
        root = createTree();
        ll turn = 0;
        ll ans = solve(root, turn);
        cout << ans << "\n";
        delete root;

    }

    return 0;
}