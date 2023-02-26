#include <iostream>
#include <queue>

#define MAX_SIZE 100001
#define X first
#define Y second
#define MAX(a, b) (((a) > (b)) ? (a) : (b)) 

using namespace std;

bool visited[MAX_SIZE];
int dist[MAX_SIZE];
int n, m, res;

bool valid(int data) {
    if(data < 0 || data >= MAX_SIZE || visited[data]) return false;
    else return true;
}


int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    queue<int> q;

    cin >> n >> m;
    
    q.push(n);
    visited[n] = true;
    dist[n] = 0;
    while(!q.empty()) {
        int cur;
        cur = q.front(); q.pop();
        int d = dist[cur];
        
        if(cur == m) {
            res = d;
            break;
        }

        if(valid(cur - 1)){
            visited[cur - 1] = true;
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if(valid(cur + 1)) {
            visited[cur + 1] = true;
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }
        if(valid(cur * 2)) {
            visited[cur * 2] = true;
            dist[cur * 2] = dist[cur] + 1;
            q.push(cur * 2);
        }
    }

    cout << res << '\n';

    return 0;
}