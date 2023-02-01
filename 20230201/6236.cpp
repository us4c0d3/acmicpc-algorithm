#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, m;
vector<int> money;

bool isPossible(int budget) {
    int cnt = 1;
    int total = budget;
    for(int i = 0; i < n; i++) {
        int day_money = money[i];
        if(day_money > budget) {
            return false;
        } 

        if(day_money > total) {
            total = budget;
            cnt++;
        }
        total -= day_money;
    }

    if(cnt > m) return false;
    else return true;
}

int main() {
    fastio;
    int left, right = 0;
    int mid;
    int res = 0;
    cin >> n >> m;

    money.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> money[i];
        right += money[i];
    }

    left = 1;
    while(left <= right) {
        mid = (left + right) / 2;

        if(isPossible(mid)) {
            right = mid - 1;
            res = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}