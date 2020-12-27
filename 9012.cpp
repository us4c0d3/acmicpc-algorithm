#include <stdio.h>
#include <string.h>
#define SIZE 60
#define STACK_SIZE 30

//push, pop, isEmpty

typedef struct _stack{
  char arr[STACK_SIZE];
  int top;
} Struct;

void stack_init(Stack * sp) {
  sp->top = -1;
}

void push(Stack * sp, char data) {
  sp->arr[++(sp->top)] = data;
}

bool isEmpty(Stack * sp) {
  if(sp->top == -1) return true;
  return false;
}

char pop(Stack * sp) {
  if(isEmpty) return;
  return sp->arr[(sp->top)--];
}

int main() {
  int n;
  Stack vps;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    int j = 0, k = 0;
    char ps[SIZE], temp;
    scanf("%s", ps);
    getchar();

    stack_init(&vps);

    while(ps[j] != "\0") {
      if(ps[j] == '(') push(&vps);
      else {
        temp = pop(&vps);
        if(temp != '(') {
          k = -1;
          break;
        }
      }
    }

    if(!isEmpty || k == -1) {
      printf("NO\n");
      break;
    }
    printf("YES\n");
  }
}