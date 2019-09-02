#include <bits/stdc++.h>


using namespace std;


class rb {

public:
    int val;
    rb *left, *right, *parent;
    bool color;
    // 1 red, 0 black

    rb(int val) {
        this->val = val;
        left = NULL;
        right = NULL;
        parent = NULL;
        color = 1;
    }


};

rb *BSTInsert(rb *root, rb *pt) {

    if (root == NULL)
        return pt;


    if (root->val < pt->val) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    } else {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    }


    return root;
}

void rr(rb *&root, rb *&pt) {

    rb *nr = pt->left;
    rb *tp = nr->right;

    rb *prt = pt->parent;

    if(prt == NULL){
        root = nr;
    }
    else{
        if (prt->left == pt) {
            prt->left = nr;
        } else {
            prt->right = nr;
        }
    }

    nr->parent = prt;


    if (tp != NULL)
        tp->parent = pt;

    pt->parent = nr;


    nr->right = pt;
    pt->left = tp;

}

void ll(rb *&root, rb *&pt){

    rb *nr = pt->right;
    rb *t = nr->left;
    rb *prt = pt->parent;

    if(prt == NULL)
        root = nr;
    else{
        if(prt->left == pt){
            prt->left = nr;
        }
        else{
            prt->right = nr;
        }
    }
    nr->parent = prt;
    pt->parent = nr;

    if(t!=NULL){
        t->parent = pt;
    }






    nr->left = pt;
    pt->right = t;

}


void fix(rb *&root, rb *&pt) {

    rb *parent = NULL;
    rb *uncle = NULL;
    rb *gparent = NULL;

    while ((pt != root) && (pt->color != 0) &&
           (pt->parent->color == 1)) {

        parent = pt->parent;
        gparent = parent->parent;

        if (parent == gparent->left) {
            uncle = gparent->right;


            if (uncle != NULL && uncle->color == 1) {
                gparent->color = 1;
                parent->color = 0;
                uncle->color = 0;
                pt = gparent;
            } else {

                if (pt == parent->right) {
                    ll(root, parent);
                    pt = parent;
                    parent = pt->parent;

                }

                rr(root, gparent);
                swap(parent->color, gparent->color);
                pt = parent;

            }


        } else {
            uncle = gparent->left;

            if (uncle != NULL && uncle->color == 1) {
                gparent->color = 1;
                parent->color = 0;
                uncle->color = 0;
                pt = gparent;
            } else {

                if (pt == parent->left) {
                    rr(root, parent);
                    pt = parent;
                    parent = pt->parent;
                }

                ll(root, gparent);
                swap(parent->color, gparent->color);
                pt = parent;

            }
        }
    }

    root->color = 0;
}
void levelOrder(rb *root) {

    queue<rb *> q;

    q.push(root);

    while (!q.empty()) {

        int n = q.size();
        for (int i = 0; i < n; i++) {
            rb *r = q.front();
            q.pop();
            cout << " (" << r->val << " - " << r->color  << ") ";
            if (r->left != NULL)
                q.push(r->left);
            if (r->right != NULL)
                q.push(r->right);

        }
        cout << "\n";

    }

}

rb *insert(rb *root, int val) {

    rb *pt = new rb(val);
    root = BSTInsert(root, pt);

    fix(root, pt);

    return  root;

}


int main() {

//    vector<int> A = {7, 3, 18, 10};
    vector<int> A = {7, 3, 18, 10, 22, 8, 12, 26, 11};

    int n = A.size();
    rb *root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, A[i]);
    }

    levelOrder(root);
    return 0;
}