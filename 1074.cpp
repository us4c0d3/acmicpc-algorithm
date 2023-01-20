#include <iostream>
#include <cmath>
using namespace std;

int N, R, C;
int cnt;

void Z(int r, int c, int size) {
    if(r == R && c == C) {
        cout << cnt << '\n';
        return;
    }

    if(R < r + size && R >= r && C < c + size && C >= c) {
        Z(r, c, size / 2);
        Z(r, c + (size / 2), size / 2);
        Z(r + (size / 2), c, size / 2);
        Z(r + (size / 2), c + (size / 2), size / 2);
    } 
    else cnt += size * size;
}

int main() {
    cin >> N >> R >> C;
    Z(0, 0, (int)pow(2, N));
    return 0;
}