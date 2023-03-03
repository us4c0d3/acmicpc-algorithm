#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, k;
bitset<32> bs;

// 물통 개수는 비트 개수
int solve() {
    int res = 0;
    bs = n;
    if(k >= bs.count()) return 0;
    
    while(1) {
        if(k >= bs.count()) break;
        bs = ++n; res++;
    }

    return res;
}


int main() {
    fastio;
    cin >> n >> k;
    cout << solve() << endl;

    return 0;
}