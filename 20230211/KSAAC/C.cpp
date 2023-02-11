#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int arr[3];

int main() {
    fastio;
    int n;
    double a = 0, b = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        arr[t % 3]++;
    }

    a = arr[1] - arr[2];
    b = arr[0] - arr[2];

    cout << a << " " << b << endl;

    return 0;
}