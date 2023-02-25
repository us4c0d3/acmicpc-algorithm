#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n, m;
vector<int> input;

bool isPossible(int blueray) {
    int sum = 0;
    int cnt = 1;

    for(int i = 0; i < n - 1; i++) {
        sum += input[i];
        if(sum + input[i + 1] > blueray) {
            sum = 0;
            cnt++;
        }
    }

    if(cnt <= m) return true;
    else return false;
}

int main() {
    fastio;
    int left, right = 0;
    int mid;
    int res = 0;
    cin >> n >> m;

    input.assign(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> input[i];
        right += input[i];
    }

    left = *max_element(input.begin(), input.end());
    while(left <= right) {
        mid = (left+right) / 2;

        if(isPossible(mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << res << endl;
    return 0;
}