#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int n;
int arr[51];

/*
1. 수열의 길이가 1인 경우
    a와 b가 여러 개 -> A

2. 수열의 길이가 2인 경우
    0과 1이 같은 경우 -> a = 1, b = 0으로 고정 => arr[0]출력
    0과 1이 다른 경우 -> A

3. 수열의 길이가 3 이상
    패턴 확인
    a = (arr[1] - arr[2]) / (arr[0] - arr[1]), b = arr[1] - a * arr[0]
*/

void solve() {
    if(n == 1) {
        cout << "A" << endl;
        return;
    }

    if(n == 2) {
        if(arr[0] == arr[1]) {
            cout << arr[0] << endl;
        } else {
            cout << "A" << endl;
        }
        return;
    }

    int t1 = arr[0] - arr[1];
    int t2 = arr[1] - arr[2];

    int a = 0;

    if(t1 != 0)
        a = t2 / t1;

    int b = arr[1] - a * arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] != a * arr[i - 1] + b) {
            cout << "B" << endl;
            return;
        }
    }

    cout << a * arr[n - 1] + b << endl;
    return;
}

int main() {
    fastio;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    solve();
    return 0;
}