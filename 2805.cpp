#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

ull n, m;
vector<ull> tree;

bool isPossible(int h) {
    ull cnt = 0;
    for(int i = 0; i < n; i++) {
        if(tree[i] >= h)
            cnt += tree[i] - h;
    }
    if(cnt >= m) return true;
    else return false;
}

int main() {
    fastio;
    ull left, right, mid;
    ull res = 0;
    cin >> n >> m;

    tree.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> tree[i];
    }
    sort(tree.begin(), tree.end());

    left = 0; right = tree[n - 1];
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