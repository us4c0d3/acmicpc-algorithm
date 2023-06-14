#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;


int r1, c1, r2, c2;
int arr[50][5];
int num = 1;
// 상 좌 하 우
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

void makeArr() {
    int x = 0, y = 0;
    int boxSize = 0;
    int cnt = 0;

    while(true) {
        if(-boxSize <= x && x <= boxSize && -boxSize <= y && y <= boxSize) {
            if(r1 <= x && x <= r2 && c1 <= y && y <= c2) {
                arr[x - r1][y - c1] = num;
                cnt++;
                if(cnt == (r2 - r1 + 1) * (c2 - c1 + 1)) return;
            }
            num++;
        }

        int dir = 0;
        while(dir < 4) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(-boxSize <= nx && nx <= boxSize && -boxSize <= ny && ny <= boxSize) {
                if(r1 <= nx && nx <= r2 && c1 <= ny && ny <= c2) {
                    arr[nx - r1][ny - c1] = num;
                    cnt++;
                    if(cnt == (r2 - r1 + 1) * (c2 - c1 + 1)) return;
                }
                num++;
                x = nx; y = ny;

            } else {
                dir++;
            }
        }

        boxSize++;
        y++;
    }
}

void printArr(int r1, int c1, int r2, int c2) {
    for(int i = r1; i <= r2; ++i) {
        for(int j = c1; j <= c2; ++j) {
            cout << setw(to_string(num).size()) << arr[i - r1][j - c1] << ' ';
        }
        cout << endl;
    }
}

int main() {
    fastio;
    cin >> r1 >> c1 >> r2 >> c2;

    makeArr();
    printArr(r1, c1, r2, c2);
    
    return 0;
}