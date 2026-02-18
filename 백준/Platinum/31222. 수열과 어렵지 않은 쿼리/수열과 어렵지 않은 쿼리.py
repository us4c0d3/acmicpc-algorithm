from sys import stdin
input = lambda: stdin.readline().rstrip()

# main code
class SegTree:
    def __init__(self, arr):
        n = len(arr)
        size = 1
        while size < n:
            size <<= 1
        self.size = size
        self.n = n
        self.data = [-1] * (2 * size)
        self.left = [-1] * (2 * size)
        self.right = [-1] * (2 * size)
        for i, v in enumerate(arr):
            self.data[self.size + i] = 1
            self.left[self.size + i] = v
            self.right[self.size + i] = v
        
        self._build(1, 0, self.size - 1)
    
    def _build(self, node, start, end):
        if start == end:
            return
        
        mid = (start + end) >> 1
        left_child = node << 1
        right_child = left_child | 1

        self._build(left_child, start, mid)
        self._build(right_child, mid + 1, end)

        if self.left[right_child] == -1:
            self.data[node] = self.data[left_child]
            self.left[node] = self.left[left_child]
            self.right[node] = self.right[left_child]
        else:
            if self.right[left_child] == self.left[right_child]:
                self.data[node] = self.data[left_child] + self.data[right_child] - 1
            else:
                self.data[node] = self.data[left_child] + self.data[right_child]

            self.left[node] = self.left[left_child]
            self.right[node] = self.right[right_child]

    def update(self, pos, val):
        self._update(1, 0, self.size - 1, pos - 1, val)

    def _update(self, node, start, end, pos, val):
        if start == end:
            self.data[node] = 1
            self.left[node] = val
            self.right[node] = val
            return
        
        mid = (start + end) >> 1
        left_child = node << 1
        right_child = left_child | 1

        if pos <= mid:
            self._update(left_child, start, mid, pos, val)
        else:
            self._update(right_child, mid + 1, end, pos, val)

        if self.left[right_child] == -1:
            self.data[node] = self.data[left_child]
            self.left[node] = self.left[left_child]
            self.right[node] = self.right[left_child]
        else:
            if self.right[left_child] == self.left[right_child]:
                self.data[node] = self.data[left_child] + self.data[right_child] - 1
            else:
                self.data[node] = self.data[left_child] + self.data[right_child]

            self.left[node] = self.left[left_child]
            self.right[node] = self.right[right_child]

    def query(self, l, r):
        return self._query(1, 0, self.size - 1, l - 1, r - 1)[0]

    def _query(self, node, start, end, l, r):
        if r < start or end < l or self.left[node] == -1:
            return None
        
        if l <= start and end <= r:
            return self.data[node], self.left[node], self.right[node]
        
        mid = (start + end) >> 1
        left_child = node << 1
        right_child = left_child | 1

        left_res = self._query(left_child, start, mid, l, r)
        right_res = self._query(right_child, mid + 1, end, l, r)

        if left_res and right_res:
            if left_res[2] == right_res[1]:
                return left_res[0] + right_res[0] - 1, left_res[1], right_res[2]
            else:
                return left_res[0] + right_res[0], left_res[1], right_res[2]
        
        return left_res or right_res


n, q = map(int, input().split())
a = [*map(int, input().split())]
seg = SegTree(a)

for _ in range(q):
    a, b, c = map(int, input().split())
    if a == 1:
        seg.update(b, c)
    else:
        print(seg.query(b, c))
