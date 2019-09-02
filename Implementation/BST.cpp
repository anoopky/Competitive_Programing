#include <bits/stdc++.h>


using namespace std;


class bst {

public:
    int val;
    bst *left;
    bst *right;

    bst(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

void insert(bst **root, int val) {

    if (*root == NULL) {
        bst *nw = new bst(val);
        *root = nw;
    } else {
        if (val > (*root)->val)
            insert(&(*root)->right, val);
        else
            insert(&(*root)->left, val);

    }
}


bst *insert1(bst *root, int val) {

    if (root == NULL) {
        bst *nw = new bst(val);
        return nw;
    } else {
        if (val > (root)->val)
            root->right = insert1(root->right, val);
        else
            root->left = insert1(root->left, val);

    }

    return root;
}


bool search(bst *root, int val) {

    if (root == NULL)
        return false;

    if (root->val == val)
        return true;

    if (root->val < val)
        return search(root->right, val);
    else
        return search(root->left, val);

}


void del(bst **root, int val) {}

void inorder(bst *root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);

}

void levelOrder(bst *root) {

    queue<bst *> q;

    q.push(root);

    while (!q.empty()) {

        int n = q.size();
        for (int i = 0; i < n; i++) {
            bst *r = q.front();
            q.pop();
            cout << r->val << " ";
            if (r->left != NULL)
                q.push(r->left);
            if (r->right != NULL)
                q.push(r->right);

        }
        cout << "\n";

    }

}

bst * mx(bst *root){

    while(root->right != NULL)
        root = root->right;

    return root;
}

bst *del(bst *root, int val) {

    if (root == NULL)
        return NULL;

    if (root->val == val) {

        if (root->left == NULL && root->right == NULL) {
            return NULL;
        } else if (root->left == NULL) {
            return root->right;
        } else if (root->right == NULL) {
            return root->left;
        } else {
            bst *tmp = mx(root->left);
            root->val = tmp->val;
            root->left = del(root->left, tmp->val);
            return root;
        }

    }
    if (root->val < val) {
        root->right = del(root->right, val);
    } else {
        root->left = del(root->left, val);
    }

    return root;
}

int main() {


    bst *root = NULL;

    vector<int> ar = {20, 10, 50, 5, 15, 30, 60, 1, 12, 16, 25, 38, 35, 70};

    int n = ar.size();

    for (int i = 0; i < n; i++) {
        insert(&root, ar[i]);
    }

//    for(int i=0; i<n; i++){
//        root = insert1(root, ar[i]);
//    }

//    inorder(root);
//    cout << "\n";

//    cout << search(root, 8) << "\n";
//    cout << search(root, -6) << "\n";

    levelOrder(root);
    cout << "\n";
//    del(root, 5);
//    del(root, 60);
//    levelOrder(root);
//    cout << "\n";
//
//    del(root, 12);
//    del(root, 70);
//    levelOrder(root);
//    cout << "\n";

//    del(root, 50);
//    levelOrder(root);
//    cout << "\n";

//    del(root, 20);
//    levelOrder(root);
//    cout << "\n";
//
    del(root, 10);
    levelOrder(root);
    cout << "\n";


}