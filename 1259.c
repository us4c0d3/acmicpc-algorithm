#include <stdio.h>
#include <string.h>

int main() {
    char str[6];
    int i;
    int status;
    while(1) {
        status = 0;
        scanf("%s", str);
        if(!strcmp(str, "0")) break;
        for(i = 0; i < strlen(str); i++) {
            if(str[strlen(str) - i - 1] != str[i]) {
                printf("no\n");
                status = 1;
                break;
            }
        }
        if(status == 0) printf("yes\n");
    }
}

