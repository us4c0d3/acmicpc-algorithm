#include <iostream>
#include <queue>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
#define MALLOC(p, s) if(!((p) = (treePointer)malloc(s))) { \
	fprintf(stderr, "Insufficient Memory"); \
	exit(EXIT_FAILURE); \
	}

typedef struct node* treePointer;

typedef struct node {
	char data;
	treePointer leftChild, rightChild;
} treeNode;

treePointer root = NULL;

void insert(char parent, char leftdata, char rightdata) {
	treePointer newleftnode, newrightnode;
	treePointer cur;
    MALLOC(newleftnode, sizeof(*newleftnode));
    MALLOC(newrightnode, sizeof(*newrightnode));
    if(leftdata == '.') newleftnode = NULL;
    else newleftnode->data = leftdata;
    if(rightdata == '.') newrightnode = NULL;
    else newrightnode->data = rightdata;
	
    queue<treePointer>q;
    q.push(root);
    while(1) {
        cur = q.front(); q.pop();
        if(cur->data == parent) break;
        if(cur) {
            if(cur->leftChild) q.push(cur->leftChild);
            if(cur->rightChild) q.push(cur->rightChild);
        } else break;
    }

    cur->leftChild = newleftnode;
    cur->rightChild = newrightnode;
}

void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data;
		inorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data;
	}
}

void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data;
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

int main() {
    fastio;
	int n;
    char parent, left, right;
    cin >> n;


    for(int i = 0; i < n; i++) {
        cin >> parent >> left >> right;
        if(root == NULL) {
            MALLOC(root, sizeof(*root));
            root->data = 'A';
            root->leftChild = NULL; root->rightChild = NULL;
        }
        insert(parent, left, right);
    }

    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;

	return 0;
}