//https://www.acmicpc.net/problem/1918
//Stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//push, pop, isEmpty, isFull, rank

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

void Push(Stack * sp, char data){
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

int Rank(char data) {
  if(data == '(') return 3;
  if(data == '*' || data == '/') return 2;
  if(data == '+' || data == '-') return 1;
  if(data == ')') return 0;
}

int main() {
  int now_rank = 0, i = 0, j = 0;
  int temp = 0;
  char infix[100];
  char postfix[100] = {0, };
  scanf("%s", infix);
  Stack oper;
  stack_init(&oper);

  while(infix[i] != '\0') {
    if(infix[i] >= 'A' && infix[i] <= 'B') {
      postfix[j] = infix[i];
      j++;
    } else {
      if(temp <= Rank(infix[i])) {
        Push(&oper, infix[i]);
        temp = Rank(infix[i]);
      } else {
        while(!isEmpty(&oper)) {
          temp = 0;
          postfix[j] = Pop(&oper);
          j++;
        }
      }
    }
    i++;
  }

  for(int k = 0; k < i; k++) {
    printf("%c", postfix[k]);
  }
  return 0;
}