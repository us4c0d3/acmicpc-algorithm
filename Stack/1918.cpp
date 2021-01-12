//https://www.acmicpc.net/problem/1918
//Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//push, pop, isEmpty, size, peek

typedef struct _stack {
  char arr[MAX_SIZE];
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

char Pop(Stack * sp) {
  if(isEmpty(sp) == 1) return -1;
  return sp->arr[(sp->top)--];
}

int Size(Stack * sp) {
  return sp->top+1;
}

char Peek(Stack * sp) {
  if(isEmpty(sp) == 1) return -1;
  return sp->arr[sp->top];
}

int main() {
  Stack num, cal;
  stack_init(&num);
  stack_init(&cal);

  

  return 0;
}