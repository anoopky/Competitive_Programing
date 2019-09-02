#include <bits/stdc++.h>

using namespace std;


int parent(int p) {
    return (p - 1) / 2;
}

int left(int p) {
    return p * 2 + 1;
}

int right(int p) {
    return p * 2 + 2;
}


void heapUP(vector<int> &heap, int p) {

    int par = parent(p);

    if (par < 0)
        return;

    if (heap[p] < heap[par]) {
        swap(heap[p], heap[par]);
        heapUP(heap, parent(p));
    }
}

void heapDown(vector<int> &heap, int p) {

    int lchild = left(p);
    int rchild = right(p);

    if(lchild < heap.size() && heap[p] > heap[lchild]){
        swap(heap[p], heap[lchild]);
        heapDown(heap, lchild);
    }
    else if(rchild < heap.size() && heap[p] > heap[rchild]){
        swap(heap[p], heap[rchild]);
        heapDown(heap, rchild);
    }

}

void insert(vector<int> &heap, int val) {

    heap.push_back(val);
    int p = heap.size() - 1;
    heapUP(heap, p);

}

int top(vector<int> &heap) {

    if(heap.size() > 0) {
        int val = heap[0];
        swap(heap[0], heap[heap.size()-1]);
        heap.pop_back();
        heapDown(heap, 0);
        return val;
    }
    else{
        return -1;
    }

}

int main() {


    vector<int> A = {2, 4, 1, 0, 3, 9, 6, 5, 7};
    int n = A.size();
    vector<int> heap;

    for (int i = 0; i < n; i++)
        insert(heap, A[i]);


    for(int i=0; i<heap.size(); i++){
        cout << heap[i] << " ";
    }
    cout << "\n";
    int x = top(heap);
    int x1 = top(heap);

    cout << x << " " << x1 << "\n";

    return 0;
}
