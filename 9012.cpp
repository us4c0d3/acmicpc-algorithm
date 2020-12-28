#include <stdio.h>
#include <string.h>
#define SIZE 60
#define STACK_SIZE 30
#define TRUE 1
#define FALSE 0

//push, pop, isEmpty, isFull

typedef struct _stack{
  int arr[STACK_SIZE];
  int top;
} Stack;

void stack_init(Stack * sp) {
  sp->top = -1;
}

bool isFull(Stack * sp) {
  if(sp->top+1 >= STACK_SIZE) return TRUE;
  return FALSE;
}

void Push(Stack * sp, char data) {
  if(isFull(sp)) return;
  sp->arr[++(sp->top)] = data;
}

bool isEmpty(Stack * sp) {
  if(sp->top == -1) return TRUE;
  return FALSE;
}

int Pop(Stack * sp) {
  if(isEmpty(sp)) return -1;
  return sp->arr[(sp->top)--];
}

int main() {
  int n;
  Stack vps;
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    int j = 0, k = 0, temp;
    char ps[SIZE];
    scanf("%s", ps);
    getchar();

    stack_init(&vps);

    while(ps[j] != '\0') {
      if(ps[j] == '(')  {
        Push(&vps, 1);
      }
      else {
        temp = Pop(&vps);
        if(temp != 1) {
          k = -1;
          break;
        }
      }
      j++;
    }

    if(!isEmpty(&vps) || k == -1) {
      printf("NO\n");
    } else {
    printf("YES\n");
    }
  }

  return 0;
}