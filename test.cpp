#include <iostream>
#include <string>
using namespace std;

int main() {
    string temp1, temp2;
    getline(cin, temp1);
    temp2 = temp1.substr(10, temp1.length());
    cout << temp2 << '\n';
}