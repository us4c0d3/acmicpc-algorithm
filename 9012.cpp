#include <stdio.h>
#include <string.h>
#define SIZE 60
#define STACK_SIZE 30
#define TRUE 1
#define FALSE 0


//push, pop, isEmpty

typedef struct _stack{
  char arr[STACK_SIZE];
  int top;
} Stack;

void stack_init(Stack * sp) {
  sp->top = -1;
}

bool isEmpty(Stack * sp) {
  if(sp->top == -1) return TRUE;
  return FALSE;
}

void Push(Stack * sp, char data) {
  sp->arr[++(sp->top)] = data;
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

    while(ps[j] != '\0') {
      if(ps[j] == '(')  {
        Push(&vps);
      }
      else {
        temp = Pop(&vps);

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

  return 0;

}