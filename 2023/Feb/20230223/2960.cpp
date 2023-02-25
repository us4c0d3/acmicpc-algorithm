#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

bool isPrime[1001];
int n, k;
int cnt = 0;

int Eratos() {
    for(int i = 2; i <= n; i++) {
        isPrime[i] = true;
    }
    for(int i = 2; i <= n; i++) {
        if(isPrime[i]) {
            for(int j = i; j <= n; j += i) {
                if(isPrime[j]) {
                    isPrime[j] = false;
                    cnt++;
                    if(cnt == k) return j;
                }
            }
        }
    }
    return 1;
}

int main() {
    fastio;
    cin >> n >> k;
    
    cout << Eratos() << endl;
    return 0;
}