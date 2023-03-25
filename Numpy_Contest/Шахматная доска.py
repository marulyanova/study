import matplotlib.pyplot as plt
import numpy as np

f = open("input.txt")
h, w = map(int, f.readline().split())

pixels = []
v1 = [0] * w
v2 = [0] * w
for i in range (w):
    if i % 2 == 0:
        v1[i] = 0
    else:
        v1[i] = 255
for i in range (w):
    if i % 2 != 0:
        v2[i] = 0
    else:
        v2[i] = 255

for i in range(h):
    if i % 2 == 0:
        pixels.append(v1)
    else:
        pixels.append(v2)

image = np.array(pixels, int)
print(image)
'''plt.imshow(image)
plt.show()'''
