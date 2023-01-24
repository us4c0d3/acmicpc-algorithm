#include <iostream>
#include <cmath>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define MOD 1234567891
using namespace std;

int main() {
    fastio;
    string str;
    int a, l;
    int res = 0;
    long long r = 1;
    
    cin >> l;
    cin >> str;
    for(int i = 0; i < l; i++) {
        a = str[i] - 'a' + 1;
        res = (res + ((a * r) % MOD)) % MOD;
        r = (r * 31) % MOD;
    }

    cout << res << endl;
}