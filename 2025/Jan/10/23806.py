import sys

input = sys.stdin.readline
n = int(input())

def print_up_down(n):
    for _ in range(n):
        for i in range(n * 5):
            print('@', end='')
        print()

def print_middle(n):
    for _ in range(n * 3):
        for i in range(n):
            print('@', end='')
        for i in range(n * 3):
            print(' ', end='')
        for i in range(n):
            print('@', end='')
        print()


print_up_down(n)
print_middle(n)
print_up_down(n)
