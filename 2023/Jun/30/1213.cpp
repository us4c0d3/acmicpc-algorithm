#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int alpha[26];

int main() {
    fastio;
    string input;
    int flag = -1;
    cin >> input;
    for(int i = 0; i < input.size(); i++) {
        alpha[input[i] - 'A']++;
    }

    for(int i = 0; i < 26; i++) {
        if(alpha[i] % 2 == 1) {
            if(flag == -1) flag = i;
            else {
                cout << "I'm Sorry Hansoo" << endl;
                return 0;
            }
        }
    }

    string res = "";
    alpha[flag]--;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < alpha[i] / 2; j++) {
            res += (char)(i + 'A');
        }
    }
    if(alpha[flag] != -1)
        res += (char)(flag + 'A');
    for(int i = 26 - 1; i >= 0; i--) {
        if(alpha[i] % 2 == 0) {
            for(int j = 0; j < alpha[i] / 2; j++) {
                res += (char)(i + 'A');
            }
        }
    }
    cout << res << endl;
    return 0;
}