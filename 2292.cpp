#include <iostream>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, i = 2, j = 5;
    int cnt = 2;
    cin >> n;
    if(n == 1) cout << '1' << endl;
    else {
        while(1) {
            if(n >= i && n <= i + j) {
                cout << cnt << endl;
                break;
            }
            i = i + j + 1;
            j += 6;
            cnt++;
        }
    }
}