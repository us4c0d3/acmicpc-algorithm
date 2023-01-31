#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length()) return a < b;
    else return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    vector<string>v;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    stable_sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        if(i == 0 || v[i] != v[i-1]) cout << v[i] << '\n';
    }

    return 0;
}