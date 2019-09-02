#include <bits/stdc++.h>


using namespace std;

class node {

public:
    int val;
    node *left;
    node *right;
    int height;

    node(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
        height = 1;
    }


};

int height(node *root) {
    if (root == NULL)
        return 0;

    return root->height;
}


int balance(node *root) {

    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

int update(node *root) {
    return 1 + max(height(root->left),
                   height(root->right));
}

node *RR(node *root) {

    node *x = root->left;
    node *t2 = x->right;

    x->right = root;
    root->left = t2;
//    cout << x->val << " " << x->height << "\n";
//    cout << root->val << " " << root->height << "\n";

    root->height = update(root);
    x->height = update(x);


    return x;

}

node *LL(node *root) {

    node *y = root->right;
    node *t2 = y->left;

    y->left = root;
    root->right = t2;

    root->height = update(root);
    y->height = update(y);

    return y;

}


node *insert(node *root, int val) {

    if (root == NULL) {
        return new node(val);
    }
    if (root->val < val) {
        root->right = insert(root->right, val);
    } else if (root->val > val) {
        root->left = insert(root->left, val);
    }

    root->height = update(root);

    int bal = balance(root);

    if (bal > 1) {

        if (height(root->left->left) >= height(root->left->right)) {
            cout << root->height << "\n\n";
            return RR(root);
        } else {
            root->left = LL(root->left);
            return RR(root);
        }

    } else if (bal < -1) {
        cout << root->val << "\n\n";
        if (height(root->right->left) <= height(root->right->right)) {
            return LL(root);
        } else {
            root->right = RR(root->right);
            return LL(root);
        }
    }

    return root;


}

node *insert1(node *root, int val) {

    if (root == NULL) {
        node *nw = new node(val);
        return nw;
    } else {
        if (val > (root)->val)
            root->right = insert1(root->right, val);
        else
            root->left = insert1(root->left, val);

    }

    return root;
}

void levelOrder(node *root) {

    queue<node *> q;

    q.push(root);

    while (!q.empty()) {

        int n = q.size();
        for (int i = 0; i < n; i++) {
            node *r = q.front();
            q.pop();
            cout << " (" << r->val << "-" << r->height << ") ";
            if (r->left != NULL)
                q.push(r->left);
            if (r->right != NULL)
                q.push(r->right);

        }
        cout << "\n";

    }

}

int main() {

    vector<int> arr = {13,10,15,5,11,16,4,6,7};
    int n = arr.size();
    node *root = NULL;
    for (int i = 0; i < n; i++) {

        root = insert(root, arr[i]);

    }

    levelOrder(root);
//    cout << "\n";
//    root = insert(root, 3);
//    levelOrder(root);
}
