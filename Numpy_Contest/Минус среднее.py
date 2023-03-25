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

sred = np.mean(m, axis = 1)
for i in range(m.shape[0]):
    for j in range(m.shape[1]):
        m[i, j] -= sred[i]
print(str(m))


