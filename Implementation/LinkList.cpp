#include<bits/stdc++.h>

using namespace std;

class linkList {

public:
    int val;
    linkList *next;

    linkList(int v) {
        val = v;
        next = NULL;
    }

};


void add(linkList **root, int val) {

    linkList *tmp = new linkList(val);
    if (*root == NULL) {
        *root = tmp;
    } else {
        linkList *tp;
        tp = *root;
//        cout << tp->val;
        while (tp->next != NULL)
            tp = tp->next;
        tp->next = tmp;
    }

}

linkList *add1(linkList *root, int val) {


    if (root == NULL)
        return new linkList(val);
    root->next = add1(root->next, val);


    return root;

}

void print(linkList *root) {

    while (root != NULL) {
        cout << root->val << "\n";
        root = root->next;
    }

    cout << "\n";

}


void del(linkList **root, int find) {

    linkList *tp = *root;
    linkList *prev = NULL;
    while (tp != NULL) {

        if (tp->val == find) {
            if (prev == NULL) {
                *root = tp->next;
            } else {
                prev->next = tp->next;
            }
            return;
        }
        prev = tp;
        tp = tp->next;
    }

}


void insert(linkList **root, int val, int pos) {


    linkList *tp, *prev = NULL;
    tp = *root;
    int i = 0;
    linkList *nw = new linkList(val);
    while (tp != NULL) {

        if (i == pos) {
            if (prev == NULL) {
                nw->next = tp;
                *root = nw;
            } else {
                nw->next = tp;
                prev->next = nw;
            }
            return;
        }

        i++;
        prev = tp;
        tp = tp->next;
    }
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};

    int n = 5;

    linkList *root = NULL;

//    for(int i=0; i<n; i++){
//        add(&root, arr[i]);
//    }

    for (int i = 0; i < n; i++) {
        root = add1(root, arr[i]);
    }

    print(root);
//
//    del(&root, 5);
//
//    print(root);
//
//    insert(&root, 3, 4);
//
//    print(root);


}