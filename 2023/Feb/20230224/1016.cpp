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
    ll m, M;
    int res;
    cin >> m >> M;

    res = M - m + 1;
    vector<bool> chk(M - m + 1, true);

    // m과 M사이의 제곱ㄴㄴ수를 구하려면 2부터 M까지의 제곱수를 m과 M사이에서 지워주면 된다. -> 당연히 TLE
    // m과 M범위에 들어가는 것만 체크 -> 제곱수로 나누고 나누어 떨어지면 그대로 진행 나누어 떨어지지 않으면 + 1
    for(ll i = 2; i * i <= M; i++) {
        ll start = m / (i * i);
        if(m % (i * i) != 0) start++;
        for(ll j = start; j * i * i <= M; j++) {
            if(chk[j * i * i - m]) {
                chk[j * i * i - m] = false;
                res--;
            }
        }
    }

    cout << res << endl;

    return 0;
}