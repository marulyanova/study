import numpy as np
b = []
f = open("input.txt")
s = 10 ** 20
for line in f:
    a = (line.split())
    b += a
    s = min(s, len(b))

m = np.array(b,float)
m = m.reshape(int(len(b) / s), s)

uni = np.unique(m, axis = 0)
print(len(uni))


