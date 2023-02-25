// https://www.acmicpc.net/problem/1920
/*
** N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.
**
** 입력
** 첫째 줄에 자연수 N(1 ≤ N ≤ 100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1 ≤ M ≤ 100,000)이 주어진다.
** 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수의 범위는 -2^31 보다 크거나 같고 2^31보다 작다.
**
** 출력
** M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

int compare(const void *a, const void *b);
int bst(int* arr, int start, int end, int target, int len);

int main() {
    int n, m;
    int t, temp;
    int* arr;

    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), compare);

    scanf("%d", &m);
    for(int i = 0; i < m; i++) {
        scanf("%d", &temp);
        if(bst(arr, 0, n, temp, n) != -1) printf("1\n");
        else printf("0\n");
    }

    return 0;
}

int compare(const void *a, const void *b) {
    if(*(int *)a > *(int *)b) return 1;
    else if(*(int *)a < *(int *)b) return -1;
    else return 0;
}

int bst(int* arr, int start, int end, int target, int len) {
    if(start > end || start >= len) return -1;
    int mid = (start + end) / 2;
    if(arr[mid] > target) return bst(arr, start, mid - 1, target, len);
    else if(arr[mid] < target) return bst(arr, mid + 1, end, target, len);
    else return mid;
}