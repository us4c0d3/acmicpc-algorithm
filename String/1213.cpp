//https://www.acmicpc.net/problem/1213
//String
#include <stdio.h>
#include <string.h>
#define PRINT printf("I\'m Sorry Hansoo\n")


int main(void) {
  char str[51];
  int alphabet[26] = {0, };
  scanf("%s", str);
  
  for(int i = 0; i < strlen(str); i++) {
    alphabet[str[i] - 'A']++;
  }

  int cnt = 0;
  
  if(strlen(str) % 2) {
    for(int i = 0; i < 26; i++) {
      if(!(alphabet[i] % 2)) {
        PRINT;
        return 0;
      }
    }
  } else {
    for(int i = 0; i < 26; i++) {
      if(!(alphabet[i] % 2)) {
        cnt++;
        if(cnt == 2) {
          PRINT;
          return 0;
        }
      }
    }
  }

  return 0;
}