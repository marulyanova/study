import numpy as np
f = open("input.txt")
k = int(f.readline())
b = []
a = list(map(int, f.readline().split()))
s1 = len(a)
while(a):
    b.append(a)
    a = list(map(int, f.readline().split()))
s2 = len(b)

while (s1 % k != 0):
    s1 += 1
while (s2 % k != 0):
    s2 += 1

s = len(b[0])
ss = len(b)
for i in range(len(b)):
    for j in range(s1 - s):
        b[i].append(0)
for i in range(s2 - ss):
    b.append([0] * s1)

ans = []
def sum(n, m, k):
    sum = 0
    for i in range(n, n + k):
        for j in range(m, m + k):
            sum += b[i][j]
    ans.append(sum)

for i in range(0, len(b), k):
    for j in range(0, len(b[0]), k):
        sum(i, j, k)

arr = np.array(ans, int)
arr = arr.reshape(s2 // k, s1 // k)
for i in range(arr.shape[0]):
    for j in range(arr.shape[1]):
        print(arr[i, j], end = " ")
    print()
