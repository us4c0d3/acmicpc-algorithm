#include <stdio.h>

int main() {
    int scale[8];
    int tmp;
    int adm = -2;    // ascending: 1, descending: -1, mixed: 0;
    scanf("%d", &scale[0]);
    for (int i = 1; i < 8; i++) {
        scanf("%d", &tmp);
        scale[i] = tmp;
        if(i == 1) adm = scale[i] - scale[i - 1];
        else {
            switch(scale[i] - scale[i - 1]) {
                case 1:
                    if(adm != 1) adm = 0;
                    break;
                case -1:
                    if(adm != -1) adm = 0;
                    break;
                default:
                    adm = 0;
                    break;
            }
        }
    }

    if(adm == -1) printf("descending\n");
    else if(adm == 1) printf("ascending\n");
    else printf("mixed\n");

    return 0;
}