#include <bits/stdc++.h>

using namespace std;

class trie {

public:
    trie *child[2];
    bool end;

    trie() {
        child[0] = NULL;
        child[1] = NULL;
        end = 0;
    }

};

trie *insert(trie *root, int val) {

    trie *tp = root;

    for (int i = 31; i >=0 ; i--) {
        int bt = (val >> i) & (1);

        if (tp->child[bt] == NULL) {
            trie *nt = new trie();
            tp->child[bt] = nt;
        }
        tp = tp->child[bt];
        if (i == 31)
            tp->end = 1;
//        val = val >> 1;

    }

    return root;
}

//void inorder(trie *root){
//
//    for(int i=0; i<2; i++){
//        if(root->child[i] != NULL){
//            cout << i << " ";
//            inorder(root->child[i]);
//        }
//    }
//
//}


int findMaximumXOR(vector<int> &nums) {

    trie *root = new trie();
    int n = nums.size();
    for (int i = 0; i < n; i++)
        root = insert(root, nums[i]);

//    inorder(root);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int val = nums[i];
        int res = 0;
        trie *tp = root;
        for (int j = 31; j >=0 ; j--) {
            int bt = (val >> j) & (1);
            int op = 1 - bt;
//            cout << bt << " " << op << " " <<val << " " << res << "\n";
            if (tp->child[op] != NULL) {
                tp = tp->child[op];
                res = (res | (1 << j));
            } else {
                tp = tp->child[bt];
                res = (res | (0 << j));
            }

//            val = val >> 1;
        }
//        cout << res << "\n";
        ans = max(ans,  res);
//        break;
    }

    return ans;
}


int main() {

    vector<int> nums = {3, 10, 5, 25, 2, 8};

    int v = findMaximumXOR(nums);
    cout << v << "\n";
    return 0;
}