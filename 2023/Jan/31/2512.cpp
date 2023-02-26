#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, budget;
vector<int> req;

bool isPossible(int b) {
    int tmp;
    int b_temp = budget;
    for(int i = 0; i < n; i++) {
        tmp = (req[i] - b >= 0) ? b : req[i];
        b_temp -= tmp;
    }

    if(b_temp >= 0) return true;
    else return false;
}

int main() {
    fastio;
    int left, right, mid;
    int res = 0;
    cin >> n;

    req.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> req[i];
    }
    cin >> budget;

    sort(req.begin(), req.end());
    left = 1; right = req[n - 1];
    while(left <= right) {
        mid = (left + right) / 2;

        if(isPossible(mid)) {
            res = max(res, mid);
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << res << endl;
    return 0;
}