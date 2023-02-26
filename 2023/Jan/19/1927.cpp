#include <iostream>
#define MAX_SIZE 100000
using namespace std;

typedef struct heap {
    int heap[MAX_SIZE];
    int size;
} Heap;

void init(Heap* h) {
    h->size = 0;
}

void insert(Heap* h, int data) {
    int i;
    i = ++(h->size);
    while(i != 1 && h->heap[i / 2] > data) {
        h->heap[i] = h->heap[i / 2];
        i /= 2;
    }
    h->heap[i] = data;
}

int delete_data(Heap* h) {
    int parent, child;
    int item, temp;
    item = h->heap[1];
    temp = h->heap[(h->size)--];
    parent = 1; child = 2;

    while(child <= h->size) {
        if((child < h->size) && (h->heap[child] > h->heap[child + 1]) )
            child++;
        
        if(temp <= h->heap[child]) break;

        h->heap[parent] = h->heap[child];

        parent = child;
        child *= 2;
    }

    h->heap[parent] = temp;

    return item;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, t;
    Heap h;
    init(&h);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        if(t) insert(&h, t);
        else {
            if(h.size == 0) cout << "0\n";
            else cout << delete_data(&h) << '\n';
        }
    }
    return 0;
}