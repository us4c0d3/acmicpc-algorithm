import sys

input = lambda: sys.stdin.readline().rstrip()

# main code
n = int(input())
st = [*input()]
st.reverse()

while True:
    if st.count('s') == st.count('t'):
        break
    st.pop()

st.reverse()
print(*st, sep='')