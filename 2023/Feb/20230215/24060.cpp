#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;
using ll = long long;
using ull = unsigned long long;
using u = unsigned;
using pii = pair<int, int>;

int cnt = 0;

void merge_sort(int A[], int p, int r, int k);
void merge(int A[], int p, int q, int r, int k);

int main() {
    fastio;
    int n, k;
    int *a;
    cin >> n >> k;
    a = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    merge_sort(a, 0, n-1, k);
    if(cnt < k) cout << -1 << endl;
    return 0;
}

void merge_sort(int A[], int p, int r, int k) { // A[p..r]을 오름차순 정렬한다.
    if (p < r) {
        int q = (p + r) / 2;       // q는 p, r의 중간 지점
        merge_sort(A, p, q, k);      // 전반부 정렬
        merge_sort(A, q + 1, r, k);  // 후반부 정렬
        merge(A, p, q, r, k);        // 병합
    }
}

// A[p..q]와 A[q+1..r]을 병합하여 A[p..r]을 오름차순 정렬된 상태로 만든다.
// A[p..q]와 A[q+1..r]은 이미 오름차순으로 정렬되어 있다.
void merge(int A[], int p, int q, int r, int k) {
    int tmp[r + 2];
    int i = p; int j = q + 1; int t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j])
            tmp[t++] = A[i++]; // tmp[t] = A[i]; t++; i++;
        else tmp[t++] = A[j++]; // tmp[t] = A[j]; t++; j++;
    }
    while (i <= q)  // 왼쪽 배열 부분이 남은 경우
        tmp[t++] = A[i++];
    while (j <= r)  // 오른쪽 배열 부분이 남은 경우
        tmp[t++] = A[j++];
    i = p; t = 1;
    while (i <= r) {  // 결과를 A[p..r]에 저장
        A[i++] = tmp[t++];
        if(++cnt == k) cout << tmp[t-1] << endl;
    }
}