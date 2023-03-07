#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

//     +---+        
//     | D |        
// +---+---+---+---+
// | E | A | B | F |
// +---+---+---+---+
//     | C |        
//     +---+        

// A-F, B-E, C-D
// 3면이 최소값인 경우, 2면이 최솟값인 경우, 1면이 최솟값인 경우
// 3면 - 꼭짓점: 4
// 2면 - 1층 제외 모서리 + 1층 꼭짓점: (n-2) * 8 + 4 
// 1면 - 테두리 제외 나머지 + 1층 테두리: (n-2)^2 * 5 + (n-2) * 4

int n;
vector<int> v(6);

void solve() {
    ll res = 0;
    ll minAF, minBE, minCD;
    ll min1, min2, min3;
    minAF = min(v[0], v[5]);
    minBE = min(v[1], v[4]);
    minCD = min(v[2], v[3]);

    min1 = min(min(minAF, minBE), minCD);
    min3 = minAF + minBE + minCD;
    min2 = min3 - max(max(minAF, minBE), minCD);
    
    if(n == 1) {
        sort(v.begin(), v.end());
        for(int i = 0; i < 5; i++) {
            res += v[i];
        }
    } else
        res = (min3 * 4) + (min2 * ((n-2) * 8 + 4)) + (min1 * ((ll)pow(n-2, 2) * 5 + (n-2) * 4));

    cout << res << endl;
}

int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    solve();
    return 0;
}