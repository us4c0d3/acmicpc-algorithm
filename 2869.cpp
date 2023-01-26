#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;

int main() {
    fastio;
    int a, b, v;
    int res;
    cin >> a >> b >> v;
    res = (v - a)/(a - b) + 1;
    if((v - a) % (a - b) != 0) cout << res + 1 << endl;
    else cout << res << endl;
    
    return 0;
}