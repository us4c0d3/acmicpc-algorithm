#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define MAX_SIZE 100000

int main() {
    fastio;
    string a, b;
    char res[MAX_SIZE + 1] = {0, };
    cin >> a >> b;

    for(int i = 0; i < MAX_SIZE; i++) {
        res[i] = ((a[i] - '0') & (b[i] - '0')) + '0';
    }
    cout << res << endl;

    for(int i = 0; i < MAX_SIZE; i++) {
        res[i] = ((a[i] - '0') | (b[i] - '0')) + '0';
    }
    cout << res << endl;

    for(int i = 0; i < MAX_SIZE; i++) {
        res[i] = ((a[i] - '0') ^ (b[i] - '0')) + '0';
    }
    cout << res << endl;

    for(int i = 0; i < MAX_SIZE; i++) {
        res[i] = a[i] == '1' ? '0' : '1';
    }
    cout << res << endl;

    for(int i = 0; i < MAX_SIZE; i++) {
        res[i] = b[i] == '1' ? '0' : '1';
    }
    cout << res << endl;
    return 0;
}