#include <iostream>
#define endl '\n'
using namespace std;

int cnt[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, t;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> t;
        cnt[t]++;
    }
    for(int i = 1; i < 10001; i++) {
        while(cnt[i]--) cout << i << endl;
    }

    return 0;
}