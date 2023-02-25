#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m, t;
    unordered_map<int, int>card;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        card[t] += 1;
    }

    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> t;
        cout << card[t] << ' ';
    }
    cout << '\n';
    return 0;
}