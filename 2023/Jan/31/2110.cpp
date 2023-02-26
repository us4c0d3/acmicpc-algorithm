#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, c;
vector<int> x;

bool isPossible(int dist) {
    int router = 1;
    int start = x[0];
    int end;
    
    for(int i = 1; i < n; i++) {
        end = x[i];
        if(end - start >= dist) {
            router += 1;
            start = end;            
        }
    }

    if(router >= c) return true;
    else return false;
}

int main() {
    fastio;
    int left, right;
    int res = 0;
    cin >> n >> c;
    x.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    left = 0; right = x[n - 1] - 1;
    while(left <= right) {
        int mid = (left + right) / 2;

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