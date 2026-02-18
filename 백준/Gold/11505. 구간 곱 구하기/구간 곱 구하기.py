from sys import stdin
input = lambda: stdin.readline().rstrip()

class SegTree:
    def __init__(self, arr):
        n = len(arr)
        size = 1
        while size < n:
            size <<= 1
        self.size = size
        self.n = n
        self.data = [1] * (size << 1)
    
        for i, v in enumerate(arr):
            self.data[self.size + i] = v
    
        self._build(1, 0, self.size - 1)

    def _build(self, node, start, end):
        # 재귀 탈출 조건
        if start == end:
            return
        
        mid = (start + end) >> 1
        left_child = node << 1
        right_child = (node << 1) + 1

        self._build(left_child, start, mid)
        self._build(right_child, mid + 1, end)

        self.data[node] = (self.data[left_child] * self.data[right_child]) % 1_000_000_007


    def update(self, pos, val):
        self._update(1, 0, self.size - 1, pos, val)


    def _update(self, node, start, end, pos, val):
        # 재귀 탈출 조건
        if start == end:
            self.data[node] = val
            return
        
        mid = (start + end) >> 1
        left_child = node << 1
        right_child = (node << 1) + 1

        if start <= pos <= mid:
            self._update(left_child, start, mid, pos, val)
        else:
            self._update(right_child, mid + 1, end, pos, val)
        
        self.data[node] = (self.data[left_child] * self.data[right_child]) % 1_000_000_007
    

    def query(self, l, r):
        return self._query(1, 0, self.size - 1, l, r)
    

    def _query(self, node, start, end, l, r):
        if r < start or end < l:
            return 1

        if l <= start and end <= r:
            return self.data[node]

        mid = (start + end) >> 1
        left_child = node << 1
        right_child = (node << 1) + 1
        
        left_mul = self._query(left_child, start, mid, l, r)
        right_mul = self._query(right_child, mid + 1, end, l, r)

        return (left_mul * right_mul) % 1_000_000_007


    def printSeg(self):
        print(self.data)


n, m, k = map(int, input().split())
nums = []
for i in range(n):
    nums.append(int(input()))
seg = SegTree(nums)

for i in range(m + k):
    a, b, c = map(int, input().split())
    if a == 1:
        seg.update(b - 1, c)
    if a == 2:
        print(seg.query(b - 1, c - 1))