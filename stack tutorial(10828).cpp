#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10000

//push, pop, isEmpty, size, top

typedef struct _stack {
  int arr[MAX_SIZE];
  int top;
} Stack;

void stack_init(Stack * sp) {
  sp->top = -1;
}

bool isEmpty(Stack * sp) {
  if(sp->top == -1) return true;
  return false;
}

bool isFull(Stack * sp) {
  if(sp->top + 1 >= MAX_SIZE) return true;
  return false;
}

void Push(Stack * sp, int data){
  if(isFull(sp) == 1) return;
  sp->arr[++(sp->top)] = data;
}

int Pop(Stack * sp) {
  if(isEmpty(sp) == 1) return -1;
  return sp->arr[(sp->top)--];
}

int Size(Stack * sp) {
  return sp->top+1;
}

int Top(Stack * sp) {
  if(isEmpty(sp) == 1) return -1;
  return sp->arr[sp->top];
}

int main(void) {
  int n, i = 0;
  Stack stack;
  stack_init(&stack);
  scanf("%d", &n);

  while(i < n) {
    int a;
    char k[6];
    scanf("%s", k);

    if(!strcmp(k , "push")) {
      scanf("%d", &a);
      Push(&stack, a);
    } else if(!strcmp(k, "size")) {
      a = Size(&stack);
      printf("%d\n", a);
    } else if(!strcmp(k, "pop")) {
      a = Pop(&stack);
      printf("%d\n", a);
    } else if(!strcmp(k, "empty")) {
      a = isEmpty(&stack);
      printf("%d\n", a);
    } else if(!strcmp(k, "top")) {
      a = Top(&stack);
      printf("%d\n", a);
    }
    i++;
  }

  return 0;
}