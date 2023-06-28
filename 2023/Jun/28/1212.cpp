#include <iostream>
#include <string>
#include <vector> 

using namespace std;

vector<string> v = {
    "000",
    "001",
    "010",
    "011",
    "100",
    "101",
    "110",
    "111"
};

int main() {
    string input, res, tmp;
    cin >> input;
    int t = input[0] - '0';
    switch(t) {
        case 0:
            res = "0";
            break;
        case 1:
            res = "1";
            break;
        case 2:
        case 3:
            res = v[t];
            res = res.substr(1);
            break;
        default:
            res = v[t];
            break;
    }
    for(int i = 1; i < input.size(); i++) {
        res += v[input[i] - '0'];
    }
    cout << res << '\n';
    return 0;
}