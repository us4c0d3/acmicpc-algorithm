//https://www.acmicpc.net/problem/10773
//Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100000

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
  int n, temp;
  Stack stack;
  stack_init(&stack);
  scanf("%d", &n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &temp);
    if(temp != 0) {
      Push(&stack, temp);
    } else {
      Pop(&stack);
    }
    
  }

  int sum = 0;

  for(int j = 0; j <= stack.top; j++) {
    sum += stack.arr[j];
  }

  printf("%d\n", sum);

  return 0;
}