#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int cnt;

int recursion(const char* s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char* s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    fastio;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cnt = 0;
        string s;
        cin >> s;
        cout << isPalindrome(s.c_str()) << ' ' << cnt << endl;
    }
    return 0;
}


// TLE; char*는 배열로, 문자열의 시작 주소만을 넘겨서 시간이 빠르지만
// c++의 string의 경우 문자열을 통째로 넘기기 때문에 속도가 느리다.
// c++ 내장 함수 중 string to char*를 처리해주는 함수가 있는데 그것은 s.c_str()이다.
/*
int cnt;

int recursion(const char* s, int l, int r){
    cnt++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const char* s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    fastio;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cnt = 0;
        string s;
        cin >> s;
        cout << isPalindrome(s.c_str()) << ' ' << cnt << endl;
    }
    return 0;
}
*/