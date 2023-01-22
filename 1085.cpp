#include <iostream>
#define endl '\n'
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
using namespace std;

int main() {
    int x, y, w, h, a, b;
    cin >> x >> y >> w >> h;
    a = MIN(w-x, h-y);
    b = MIN(x, y);

    cout << MIN(a, b) << endl;
    return 0;
}