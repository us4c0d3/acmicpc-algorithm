#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<pair<int, int>>v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    stable_sort(v.begin(), v.end());

    for(int i = 0; i < n; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    return 0;
}