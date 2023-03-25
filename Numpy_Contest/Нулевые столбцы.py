import numpy as np
b = []
f = open("input.txt")
s = 10 ** 20
for line in f:
    a = (line.split())
    b += a
    s = min(s, len(b))

m = np.array(b, float)
m = m.reshape(int(len(b) / s), s)
m = m.transpose()

countt = 0
for i in range(m.shape[0]):
    for j in range(m.shape[1]):
        if m[i, j] != 0:
            break
        if j == int(len(b) / s) - 1:
            countt += 1
print(countt)


