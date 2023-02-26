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
    int two = 0, one = 0;
    for(int i = 0; i < 3; i++) {
        int t;
        cin >> t;
        if(t == 2) two++;
        else one++;
    }

    if(two > one) cout << "2" << endl;
    else cout << "1" << endl;
    
    return 0;
}