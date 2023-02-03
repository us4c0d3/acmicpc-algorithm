#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int x, y;

int main() {
    fastio;
    int t;
    string s;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int k;
        int chk = -1;
        cin >> k >> s;
        x = 0; y = 0;
        for(int j = 0; j < k; j++) {
            switch(s[j]) {
                case 'L':
                    x -= 1;
                    break;
                case 'R':
                    x += 1;
                    break;
                case 'U':
                    y += 1;
                    break;
                case 'D':
                    y -= 1;
                    break;
            }

            if(x == 1 && y == 1) {
                chk = 1;
                break;
            }
        }

        if(chk == 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    

    return 0;
}