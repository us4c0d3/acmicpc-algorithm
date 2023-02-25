#include <iostream>
#include <string>
using namespace std;

int dequeue[20001];
int top = 20001/2, rear = 20001/2;


int empty() {
    if(top == rear) return 1;
    else return 0;
}

void push_front(int x) {
    dequeue[--top] = x;
}

void push_back(int x) {
    dequeue[rear++] = x;
}

int pop_front() {
    if(empty()) return -1;
    return dequeue[top++];
}

int pop_back() {
    if(empty()) return -1;
    return dequeue[--rear];
}

int size() {
    return rear-top;
}

int front() {
    if(empty()) return -1;
    else return dequeue[top];
}

int back() {
    if(empty()) return -1;
    else return dequeue[rear - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    for(int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);

        if(temp.compare("front") == 0) {
            cout << front() << '\n';
        } else if(temp.compare("back") == 0) {
            cout << back() << '\n';
        } else if(temp.compare("size") == 0) {
            cout << size() << '\n';
        } else if(temp.compare("empty") == 0) {
            cout << empty() << '\n';
        } else if(temp.compare("pop_front") == 0) {
            cout << pop_front() << '\n';
        } else if(temp.compare("pop_back") == 0) {
            cout << pop_back() << '\n';
        } else {
            string sub;
            if(temp[5] == 'b') {
                sub = temp.substr(10, temp.length());
                push_back(stoi(sub));
            } else {
                sub = temp.substr(11, temp.length());
                push_front(stoi(sub));
            }
        }
    }
    return 0;
}