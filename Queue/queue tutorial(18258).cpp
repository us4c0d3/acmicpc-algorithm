//https://www.acmicpc.net/problem/18258
//Queue
#include <iostream>

using namespace std;

//push, pop, size, empty, front, back

int front = 0, rear = 0;
int queue[2000000];

void Push(int x) {
  queue[rear] = x;
  rear++;
}

bool Empty() {
  return front == rear;
}

int Pop() {
  if(Empty()) return -1;
  int res = queue[front];
  front++;
  return res;
}

int Size() {
  return rear - front;
}

int Front() {
  if(Empty()) return -1;
  return queue[front];
}

int Back() {
  if(Empty()) return -1;
  return queue[rear - 1];
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  while(n--) {
    string str;
    cin >> str;
    if(str == "push") {
      int a;
      cin >> a;
      Push(a);
    } else if(str == "pop") {
      cout << Pop() << '\n';
    } else if(str == "size") {
      cout << Size() << '\n';
    } else if(str == "front") {
      cout << Front() << '\n';
    } else if(str == "back") {
      cout << Back() << '\n';
    } else if(str == "empty") {
      cout << Empty() << '\n';
    }
  }

  return 0;
}