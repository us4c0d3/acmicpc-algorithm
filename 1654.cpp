#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int k, n;
vector<int> lan;


bool isPossible(int l) {
    int cnt = 0;
    for(int i = 0; i < k; i++) {
        cnt += lan[i] / l;
    }

    if(cnt >= n) return true;
    else return false;
}

int main() {
    fastio;
    unsigned int left, right, mid;
    unsigned int res = 0;
    cin >> k >> n;

    lan.assign(k, 0);
    for(int i = 0; i < k; i++) {
        cin >> lan[i];
    }
    sort(lan.begin(), lan.end());

    left = 1; right = lan[k - 1];
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