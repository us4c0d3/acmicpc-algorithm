#include <stdio.h>
#include <string.h>
#define MAX 50

char prev[MAX], cur[MAX];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %s", cur);
        if(strlen(prev) == 0) {
            strcpy(prev, cur);
            continue;
        }
        for(int l = 0; l < strlen(prev); l++) {
            if(prev[l] != cur[l]) cur[l] = '?'; 
        }
        strcpy(prev, cur);
    }
    printf("%s\n", prev);
}