#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, a, b;
    int sub, d, res;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        sub = b - a;
        d = sqrt(sub);
        if(pow(d, 2) == sub) res = d * 2 - 1;
        else res = d * 2;
        if(sub > d * (d + 1)) res += 1;
        cout << res << '\n';
    }
    return 0;
}