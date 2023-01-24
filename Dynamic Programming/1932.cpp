#include <iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;

int max(int a, int b) {return a>b?a:b;}

int tri[500][500];
int main() {
    fastio;
    int n, i, j;
    int maxSum = 0;
    cin >> n;

    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            if(j == 0) tri[i][j] += tri[i - 1][0];
            else if(i == j) tri[i][j] += tri[i - 1][j - 1];
            else tri[i][j] += max(tri[i - 1][j], tri[i - 1][j - 1]);

            maxSum = max(maxSum, tri[i][j]);
        }
    }
    cout << maxSum << endl;
    return 0;
}