import matplotlib.pyplot as plt
import numpy as np

f = open("input.txt")
h, w = map(int, f.readline().split())
r1, g1, b1 = map(int, f.readline().split())
r2, g2, b2 = map(int, f.readline().split())

pixels = [[(r1, g1, b1)] * w] * (h - 4)
ram = [[(r2, g2, b2)] * w] * 2
pixels = ram + pixels + ram

for i in range (2):
    for j in range(h):
        pixels[j][i] = (r2, g2, b2)
        pixels[j][w - i - 1] = (r2, g2, b2)

#print(pixels)
image = np.array(pixels, int)
print(image)
'''plt.imshow(image)
plt.show()'''
