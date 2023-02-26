#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int main() {
    fastio;
    int n, l;
    int start = -1234, end = -1234;
    cin >> n >> l;
    for(int i = l; i <= 100; i++) {
        if(i % 2 == 1) {
            if(n % i == 0) {
                start = n / i - i / 2;
                end = n / i + i / 2;
                break;
            }
        } else {
            if(n % i == i / 2) {
                start = n / i - i / 2 + 1;
                end = n / i + i / 2;
                break;
            }
        }
    }

    if(start < 0) cout << -1;
    else for(int i = start; i <= end; i++) cout << i << " ";
    cout << endl;

    return 0;
}